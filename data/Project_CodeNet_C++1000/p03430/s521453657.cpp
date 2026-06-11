#include <bits/stdc++.h>
using namespace std;

string s;
int k, n, dp[302][302][302];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> k;
	n = s.size();
	s = 'N' + s;
	for(int i = 1; i <= n; ++i) {
		dp[0][i][i] = 1;
		if(i < n) dp[0][i][i + 1] = 1 + (int)(s[i] == s[i + 1]);
	}
	for(int i = 2; i < n; ++i) {
		for(int j = 1; j + i <= n; ++j) {
			dp[0][j][j + i] = max(dp[0][j + 1][j + i], dp[0][j][j + i - 1]);
			if(s[j] == s[j + i]) dp[0][j][j + i] = dp[0][j + 1][j + i - 1] + 2;
		}
	}
	for(int r = 1; r <= k; ++r) {
		for(int i = 1; i <= n; ++i) {
			dp[r][i][i] = 1;
			if(i < n) dp[r][i][i + 1] = 2;
		}
		for(int i = 2; i < n; ++i) {
			for(int j = 1; j + i <= n; ++j) {
				if(s[j] == s[j + i]) dp[r][j][j + i] = dp[r][j + 1][j + i - 1] + 2;
				dp[r][j][j + i] = max(max(dp[r][j + 1][j + i], dp[r][j][j + i]), max(dp[r][j][j + i - 1], dp[r - 1][j + 1][j + i - 1] + 2));
			}
		}
	}
	cout << dp[k][1][n] << endl;
	return 0;
}