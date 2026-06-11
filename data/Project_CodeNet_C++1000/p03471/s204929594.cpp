#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	int n, y;
	cin >> n >> y;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			int m = n - i - j;
			if (m < 0) continue;
			int money = 10000 * i + 5000 * j + 1000 * m;
			if (money == y) {
				cout << i << " " << j << " " << m << endl;
				return 0;
			}
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
}