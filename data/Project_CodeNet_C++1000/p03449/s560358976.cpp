#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, a[2][100];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[0][i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[1][i];
	}

	int dp[2][100];
	dp[0][0] = a[0][0];
	dp[1][n - 1] = a[1][n - 1];

	for (int i = 0; i < n-1; ++i) {
		dp[0][i + 1] = dp[0][i] + a[0][i + 1];
		dp[1][n - 2 - i] = dp[1][n - 1 - i] + a[1][n -2 - i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[0][i] + dp[1][i]);
	}
	cout << ans << endl;

	return 0;
}