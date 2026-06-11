#include <bits/stdc++.h>
using namespace std;
int main (){
	vector <pair <int, int> > rutas;
	pair <int, int> pares;
	int n, t , pasaje, minutos, p_min, r = 0; bool uno = true;
	cin >> n >> t;
	for (int i=1;i<=n;i++){
		cin >> pasaje >> minutos;
		if (minutos <= t){
			if (uno == true){
				p_min = pasaje;
				uno = false;
				r = pasaje;
			}
			else{
				if (pasaje < p_min){
					p_min = pasaje;
					r = pasaje;
				}
			}
		}
	}
	if (r == 0) cout << "TLE";
	else cout << r;
	
}