// practice with Dukkha, coached by rainboy
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 10000;

int d2c[] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int dd[8];
int dp[N + 1];

int main() {
	int n, m; cin >> n >> m;
	while (m--) {
		int d; cin >> d;
		int c = d2c[d];
		dd[c] = max(dd[c], d);
	}
	fill(dp, dp + n + 1, -1);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int k = dp[i];
		if (k == -1)
			continue;
		for (int c = 2; c <= 7 && i + c <= n; c++)
			if (dd[c])
				dp[i + c] = max(dp[i + c], k + 1);
	}
	for (int i = n; i > 0; ) {
		int d_ = 0, c_ = 0;
		for (int c = 2; c <= 7 && i - c >= 0; c++) {
			int d = dd[c];
			if (d_ < d && dp[i] == dp[i - c] + 1) {
				d_ = d;
				c_ = c;
			}
		}
		cout << d_;
		i -= c_;
	}
	cout << '\n';
	return 0;
}
