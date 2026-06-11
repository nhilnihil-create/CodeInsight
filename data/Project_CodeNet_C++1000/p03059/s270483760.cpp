#include<bits/stdc++.h>
#include<iomanip>

#define ll long long
#define ar array
 
using namespace std;


int main() {
	
	int r;
	double a,b,c,aux;
	
	cin >> a >> b >> c;
	
	aux = c + 0.5;
	
	r = aux/a;
	if(c<(a-0.5)){
		r=0;
	}
	cout << r*b <<endl;
	
	
   	return 0;
}
