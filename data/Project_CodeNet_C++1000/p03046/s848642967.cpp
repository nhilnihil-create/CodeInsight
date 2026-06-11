#include <bits/stdc++.h>
using namespace std;

signed main () {
	int m, k;
	cin >> m >> k;
	if (m == 1) {
		if (k >= 1)
			cout << "-1\n";
		else
			cout << "0 1 1 0\n";
	}
	else if (k >= (1 << m))
		cout << "-1\n";
	else {
		for (int i = 0; i < (1 << m); ++i) {
			if (i != k)
				cout << i << ' ';
		}
		cout << k << ' ';
		for (int i = (1 << m) - 1; i >= 0; --i) {
			if (i != k)
				cout << i << ' ';
		}
		cout << k << '\n';
	}
}
