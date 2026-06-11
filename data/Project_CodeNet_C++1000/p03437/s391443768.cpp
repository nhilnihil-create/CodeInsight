#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int x, y;
	cin >> x >> y;

	if (x % y == 0) {
		cout << -1 << endl;
	}
	else {
		cout << x << endl;
	}

	return 0;
}