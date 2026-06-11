#include <iostream>
using namespace std;
main(){
//Si la distancia entre Alice y Borys en impar, Borys gana.
//Esto es porque al iniciar Alice, la distancia impar le permite
//"Empujar" a Borys hasta uno de los bordes del tablero

	int s,a,b;
	cin>>s>>a>>b;
	cout<<((b-a)%2?"Borys":"Alice");

}
