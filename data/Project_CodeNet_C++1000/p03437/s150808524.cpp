#include <bits/stdc++.h>
using namespace std;
int main() {
	int64_t x, y;
	cin >> x >> y;
	int64_t ans = -1;

	int64_t a = 0;
	if (x % y == 0) {
		cout << -1 << endl;
		return 0;
	}
	while (true) {
		a += x;
		if (x % y != 0) {
			ans = x;
			break;
		}
	}

	cout << ans << endl;
}