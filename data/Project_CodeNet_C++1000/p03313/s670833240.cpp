#include <bits/stdc++.h>
using namespace std;

int a[1<<20][2];
int ans[1<<20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < 1 << n; i++) {
		cin >> a[i][0];
		a[i][1] = -1;
	}
	auto relax = [&](int &x, int &y, int x1, int y1) {
		if (x < x1) {
			y = x;
			x = x1;
		} else if (y < x1) {
			y = x1;
		}
		if (x < y1) {
			y = x;
			x = y1;
		} else if (y < y1) {
			y = y1;
		}
	};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1 << n; j++) {
			if (j >> i & 1) {
				relax(a[j][0], a[j][1], a[j - (1 << i)][0], a[j - (1 << i)][1]);
			}
		}
	}
	for (int i = 1; i < 1 << n; i++) {
		ans[i] = max(ans[i], a[i][0] + a[i][1]);
		if (i + 1 < 1 << n) ans[i + 1] = max(ans[i + 1], ans[i]);
		cout << ans[i] << '\n';
	}
	return 0;
}