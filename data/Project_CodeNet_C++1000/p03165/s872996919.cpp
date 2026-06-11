#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s, t; cin >> s >> t;
	int n = s.length();
	int m = t.length();
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	// for (auto it : dp)
	// {
	// 	for (auto it2 : it)
	// 		cout << setw(2) << it2 << " ";
	// 	cout << "\n";
	// }
	// cout << "\n";
	string ans;
	int r = n;
	int c = m;

	while (r && c)
	{
		if (dp[r][c] == dp[r - 1][c])
			r--;
		else if (dp[r][c] == dp[r][c - 1])
			c--;
		else
		{
			ans += s[r - 1];
			r--; c--;
		}
	}
	reverse(ans.begin(), ans.end());

	cout << ans;

	return 0;
}
