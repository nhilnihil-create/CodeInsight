#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	int tb = 0;
	int xb = 0;
	int yb = 0;
	int t, x, y;
	for (int i = 0; i < n; i++) {
		cin >> t >> x >> y;
		if (abs(x - xb) + abs(y - yb) > t-tb || (t - tb - abs(x - xb) - abs(y - yb)) % 2 == 1) {
			cout << "No" << endl;
			return 0;
		}
		tb = t;
		xb = x;
		yb = y;
	}
	cout << "Yes" << endl;
}