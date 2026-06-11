#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a,b,n;
	cin >> n >> a >> b;
	
	if(n * a <= b) {
		cout << n * a;
	} else {
		cout << b << endl;
	} 
	
	return 0;
}