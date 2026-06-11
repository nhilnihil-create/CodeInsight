#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	int x;
	
	cin >> a >> b;
	
	x = a + b;
	
	if(x % 2 == 1){
		cout << x / 2 + 1 << endl;
	}else {
		cout << x / 2 << endl;
	}
}