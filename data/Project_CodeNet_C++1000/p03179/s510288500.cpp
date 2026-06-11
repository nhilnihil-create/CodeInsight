#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;
	vector<vector<ll>> dp(n, vector<ll> (n, 0));
	for (int i = 0; i < n; i++)
		dp[0][i] = 1;
	for (int i = 1; i < n; i++)
	{
		vector<ll> pref(n + 1, 0);
		pref[1] = dp[i - 1][0];
		for (int j = 1; j < n; j++)
			pref[j + 1] = (pref[j] + dp[i - 1][j]) % mod;
		for (int j = 0; j < n; j++)
		{
			if (s[i - 1] == '<')
			{
				dp[i][j] = pref[j + 1] % mod;
			}
			else
			{
				dp[i][j] = (pref[n - i + 1] - pref[j + 1] + mod) % mod;
			}
		}
	}
	cout << dp[n - 1][0];

	return 0;
}