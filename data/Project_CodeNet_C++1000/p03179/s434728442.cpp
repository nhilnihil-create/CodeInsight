#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
int n;
string s;

int main()
{
	cin >> n >> s;
	long long dp[n + 1][n + 1];
	long long prefix[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	memset(prefix, 0, sizeof(dp));
	prefix[0][1] = dp[0][1] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= i + 1; j++)
		{
			if (s[i - 1] == '>')
				dp[i][j] = (dp[i][j] + (prefix[i - 1][i] - prefix[i - 1][j - 1] + MOD) % MOD) % MOD;
			else
				dp[i][j] = (dp[i][j] + prefix[i - 1][j - 1]) % MOD;
			prefix[i][j] = (prefix[i][j - 1] + dp[i][j]) % MOD;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + dp[n - 1][i]) % MOD;
	cout << ans << endl;
	return 0;
}
