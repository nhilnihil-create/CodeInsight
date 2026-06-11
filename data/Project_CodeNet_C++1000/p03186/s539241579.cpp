#include <bits/stdc++.h>

using namespace std;
int _w;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if( c > a + b ) {
		cout << a + b + 1 + b << endl;
	} else {
		cout << c + b << endl;
	}
	return 0;
}
