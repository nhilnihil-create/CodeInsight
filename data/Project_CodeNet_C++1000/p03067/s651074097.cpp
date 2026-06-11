#include<bits/stdc++.h>
using namespace std;

signed main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a < b) {
		cout << (a < c && c < b ? "Yes" : "No") << endl;
	}
	else {
		cout << (b < c && c < a ? "Yes" : "No") << endl;
	}

	return 0;
}
