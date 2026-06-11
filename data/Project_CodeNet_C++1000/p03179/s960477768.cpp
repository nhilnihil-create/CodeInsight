#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
#define MOD 1000000007
int main() {
	int n = ri();
	std::string s;
	std::cin >> s;
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	dp[0][1] = MOD - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j) {
				dp[i][j] += dp[i][j - 1];
				if (dp[i][j] >= MOD) dp[i][j] -= MOD;
			}
			if (i + 1 == n || !dp[i][j]) continue;
			if (s[i] == '>') {
				dp[i + 1][0] += dp[i][j];
				if (dp[i + 1][0] >= MOD) dp[i + 1][0] -= MOD;
				dp[i + 1][j + 1] -= dp[i][j];
				if (dp[i + 1][j + 1] < 0) dp[i + 1][j + 1] += MOD;
			} else {
				dp[i + 1][j + 1] += dp[i][j];
				if (dp[i + 1][j + 1] >= MOD) dp[i + 1][j + 1] -= MOD;
				if (i + 2 < n) {
					dp[i + 1][i + 2] -= dp[i][j];
					if (dp[i + 1][i + 2] < 0) dp[i + 1][i + 2] += MOD;
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += dp[n - 1][i];
		if (res >= MOD) res -= MOD;
	}
	std::cout << res << std::endl;
	return 0;
}
