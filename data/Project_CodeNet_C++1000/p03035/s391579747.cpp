/*A - Ferris Wheel*/
#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int edad;
	int precio;

	cin >> edad >> precio;

	if(edad <= 5)
		cout << "0";
	else if(edad <= 12)
		cout << precio/2;
	else
		cout << precio;

	return 0;
}