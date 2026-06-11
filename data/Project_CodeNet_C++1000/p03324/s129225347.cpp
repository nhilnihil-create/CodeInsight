#include <bits/stdc++.h>
using namespace std;

int main(){
	int d,n;
	cin >> d >> n;
	if (d==0 && n == 100) {cout << 101; return 0;}
	if (d==1 && n == 100) {cout << 10100; return 0;}
	if (d==2 && n == 100) {cout << 1010000; return 0;}
	cout << pow(10,d*2) *n;
	
		
 }
