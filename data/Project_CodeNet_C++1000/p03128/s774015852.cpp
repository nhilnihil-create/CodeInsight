// practice with Dukkha, coached by rainboy
#include <algorithm>
#include <iostream>

using namespace std;

const int N_ = 54;

int d2c[] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int dd[8];
int dp[N_ + 1];
int kk[10];

int main() {
	int n, m; cin >> n >> m;
	while (m--) {
		int d; cin >> d;
		int c = d2c[d];
		dd[c] = max(dd[c], d);
	}
	int c_ = 2;
	while (dd[c_] == 0)
		c_++;
	int n_ = 0;
	for (int c = c_ + 1; c <= 7; c++)
		n_ += c * (c_ - 1);
	fill(dp, dp + n_ + 1, -1);
	dp[0] = 0;
	for (int i = 0; i < n_; i++) {
		int k = dp[i];
		if (k == -1)
			continue;
		for (int c = c_; c <= 7 && i + c <= n_; c++)
			if (dd[c])
				dp[i + c] = max(dp[i + c], k + 1);
	}
	int k = (n - n_ + c_ - 1) / c_;
	kk[dd[c_]] += k;
	n -= c_ * k;
	while (n) {
		c_ = 0;
		for (int c = 2; c <= 7 && n - c >= 0; c++)
			if (dd[c_] < dd[c] && dp[n] == dp[n - c] + 1)
				c_ = c;
		kk[dd[c_]]++;
		n -= c_;
	}
	for (int d = 9; d; d--)
		while (kk[d]--)
			cout << d;
	cout << '\n';
	return 0;
}
