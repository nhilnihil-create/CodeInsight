#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,X,Y;
	cin >> a >> b;
	X = a%2;
	Y = b%2;
	if ((X == 0)||(Y == 0)){
		cout << "Even" << endl;
	}
	else {
		cout << "Odd" << endl;
	}
	
}