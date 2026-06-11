#include <bits/stdc++.h>
using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output14.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s, t;
	cin >> s >> t;
	int n1, n2;
	n1 = s.length();
	n2 = t.length();
	vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= n2; j++)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	// for (int i = 1; i <= n1; i++)
	// {
	// 	for (int j = 1; j <= n2; j++)
	// 	{
	// 		cout << dp[i][j] << "     ";
	// 	}
	// 	cout << "\n";
	// }
	string ans;
	int m = n1, n = n2;
	while (m > 0 && n > 0)
	{
		if (dp[m][n] == dp[m - 1][n])
			m--;
		else if ((dp[m][n] == dp[m][n - 1]))
			n--;
		else
		{

			ans = s[m - 1] + ans;
			n--;
			m--;
		}
	}
	cout << ans << "\n";
//cout << "\n";
}