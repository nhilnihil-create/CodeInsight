#include <bits/stdc++.h>
using namespace std;

long long X,Y,i,mult;

int main () {
	cin >> X >> Y;
	for(i=1; i<100; i++){
		mult = pow(2, i)*X;
		//pake fungsi eksponen
		if (mult>Y){
			cout << i << endl;;
			break;
		}
	}	
}