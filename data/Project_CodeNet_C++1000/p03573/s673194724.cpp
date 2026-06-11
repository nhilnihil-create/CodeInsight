#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, n;
	cin >> a >> b >> c;
	if(a == b){
		n = c;
	}else if(b == c){
		n = a;
	}else{
		n = b;
	}
	cout << n << endl;
}
