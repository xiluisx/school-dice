#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Dado
{
    int NumCaras;
    int Valor = 1;

public:
    Dado()
    {
        NumCaras = 6;
    }
    Dado(int NumCaras)
    {
        this->NumCaras = NumCaras;
    }
    void TirarDado()
    {
        Valor = rand() % NumCaras + 1;
    }
    int GetValor()
    {
        return Valor;
    }
};

class Jugador
{
public:
    int UltimoNumero = 0;
};

string GetGanador(Jugador jugador1, Jugador jugador2)
{
    if(jugador1.UltimoNumero == jugador2.UltimoNumero)
        return "Empate.";
    if(jugador1.UltimoNumero > jugador2.UltimoNumero)
    {
        return "El Jugador 1 gano.";   
    }
    else
    {
        return "El Jugador 2 gano.";
    }
}

int main()
{
    srand(time(NULL));
    
    Dado dado;
    Jugador jugador1,jugador2;
    cout << "Jugador 1 presiona enter para tirar..."<<endl;
    std::cin.ignore();
    cout << "El jugador 1 tiro el dado..." << endl;
    dado.TirarDado();
    jugador1.UltimoNumero = dado.GetValor();
    cout << "Jugador 1 saco: " << jugador1.UltimoNumero << endl << endl;
    
    cout << "Jugador 2 presiona enter para tirar..."<<endl;
    std::cin.ignore();
    cout << "El jugador 2 tiro el dado..." << endl;
    dado.TirarDado();
    jugador2.UltimoNumero = dado.GetValor();
    cout << "Jugador 2 saco: " << jugador2.UltimoNumero << endl<<endl;
    
    cout << GetGanador(jugador1,jugador2) << endl;
}