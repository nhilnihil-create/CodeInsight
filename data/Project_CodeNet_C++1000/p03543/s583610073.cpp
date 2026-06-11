#include <bits/stdc++.h>
using namespace std;

int main() {
	char a, b, c, d;
	cin >> a >> b >> c >> d;
	
	if (b == c && (a == b || c == d)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
