#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	
	long long dp[n - 1][n + 1];
	memset(dp, 0, sizeof(dp));
	(s[0] == '<' ? dp[0][2] = 1 : dp[0][1] = 1);
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '>') {
			dp[i][i + 2] = 0;
			for (int j = i + 1; j; j--) {
				dp[i][j] = (dp[i][j + 1] + dp[i - 1][j])%mod;
			}
		} else {
			dp[i][1] = 0;
			for (int j = 2; j <= i + 2; j++) {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1])%mod;
			}
		}
	}
	long long ans{};
	for (int i = 1; i <= n; i++) ans = (ans + dp[n - 2][i])%mod;
	cout << ans;
}