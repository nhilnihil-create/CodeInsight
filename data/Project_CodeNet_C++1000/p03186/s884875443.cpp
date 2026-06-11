#include <bits/stdc++.h>
using namespace std;
int a , b , c , tot;
int main(){
	cin >> a >> b >> c;
	if(b >= c){
		cout << b + c << endl;
	}
	else if(a + b >= c){
		cout << b + c << endl;
	}
	else if(a + b < c){
		cout << (2*b) + a + 1 << endl;
	}
}