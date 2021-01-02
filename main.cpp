#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir directorio;
    directorio.setPath("C:/Actividad QT");
    qDebug() << "\nObteniendo información de" << directorio.absolutePath() << ":";
    QFileInfoList contenido = directorio.entryInfoList();
    foreach (const QFileInfo &info, contenido) {
        qDebug() << "Nombre:" << info.fileName();
        qDebug() << "Es directorio:" << info.isDir();
        qDebug() << "Se puede escribir:" << info.isWritable();
        qDebug() << "Última de creación:" << info.lastModified().toString();
        qDebug() << "-------------------";
    }
    // Listar contenido mediante un filtro
    qDebug() << "\nListar archivos de C++ ordenados:";
    QStringList extenciones = {"*.cpp", "*.h"};
    contenido = directorio.entryInfoList(extenciones, QDir::Files, QDir::Name);
    foreach (const QFileInfo &info, contenido) {
        qDebug() << info.fileName();
    }
    // Cambiando de directorio
    QString carpeta = "Carpeta1";
    qDebug() << "\nIngresando a" << carpeta;
    if (!directorio.cd(carpeta)){
        qWarning() << "No existe el direcotorio" << carpeta;
    }else{
        QStringList contenido = directorio.entryList();
        foreach (QString elemento, contenido) {
            qDebug() << elemento;
        }
        directorio.cdUp();
    }
    //Creando un nuevo directorio
    qDebug() << "\nCreando un directorio:";
    QString nuevo = "Carpeta6";
    if (directorio.mkdir(nuevo)){
        qDebug() << nuevo << "creado con exito!";

        QStringList contenido = directorio.entryList(QDir::Dirs);
        foreach (QString elemento, contenido) {
            qDebug() << elemento;
        }

    }else{
        qWarning() << "No se pudo crear el directorio" << nuevo;
    }
/////////////////////////////////////////////////////////////////////////////////
    qDebug() << "\nBorrando un directorio:";
    QString  nuevos= "Carpeta3";
    if (directorio.rmdir(nuevos)){
        qDebug() << nuevos << "borrado con exito!";

        QStringList contenido = directorio.entryList(QDir::Dirs);
        foreach (QString elemento, contenido) {
            qDebug() << elemento;
        }

    }else{
        qWarning() << "No se pudo borrar el directorio" << nuevo;
    }
////////////////////////////////////////////////////////////////////////////////////

    return a.exec();
}
