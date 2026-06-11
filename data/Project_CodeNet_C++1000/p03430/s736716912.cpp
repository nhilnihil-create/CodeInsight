#include <bits/stdc++.h>

using namespace std;

int maxlcs(string s1, string s2, int k)
{
	if (s1.empty() || s2.empty())
		return 0;
	vector<vector<vector<int>>> ans(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(k + 1)));
	for (int i = 0; i <= s1.size(); ++i)
		for (int j = 0; j <= s2.size(); ++j)
			for (int l = 0; l <= k; ++l)
			{
				if (i < s1.size())
					ans[i + 1][j][l] = max(ans[i + 1][j][l], ans[i][j][l]);
				if (j < s2.size())
					ans[i][j + 1][l] = max(ans[i][j + 1][l], ans[i][j][l]);
				if (l < k)
					ans[i][j][l + 1] = max(ans[i][j][l + 1], ans[i][j][l]);
				if (i < s1.size() && j < s2.size())
				{
					if (s1[i] == s2[j])
						ans[i + 1][j + 1][l] = max(ans[i + 1][j + 1][l], ans[i][j][l] + 1);
					else if (l < k)
						ans[i + 1][j + 1][l + 1] = max(ans[i + 1][j + 1][l + 1], ans[i][j][l] + 1);
				}
			}
	return ans.back().back().back();
}

int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int k;
	cin >> k;
	vector<vector<vector<int>>> dp(s.size() + 1, vector<vector<int>>(s.size() + 1, vector<int>(k + 1)));
	int n = s.size();
	for (int i = 0; i < n; ++i)
		dp[i][i + 1][0] = 1;
	for (int len = 0; len <= n; ++len)
		for (int i = 0; i + len <= n; ++i)
		{
			int j = i + len;
			for (int l = 0; l <= k; ++l)
			{
				if (j < n)
					dp[i][j + 1][l] = max(dp[i][j + 1][l], dp[i][j][l]);
				if (i > 0)
					dp[i - 1][j][l] = max(dp[i - 1][j][l], dp[i][j][l]);
				if (l < k)
					dp[i][j][l + 1] = max(dp[i][j][l + 1], dp[i][j][l]);
				if (i > 0 && j < n)
				{
					if (s[i - 1] == s[j])
						dp[i - 1][j + 1][l] = max(dp[i - 1][j + 1][l], dp[i][j][l] + 2);
					else if (l < k)
						dp[i - 1][j + 1][l + 1] = max(dp[i - 1][j + 1][l + 1], dp[i][j][l] + 2);
				}
			}
		}
	cout << dp[0].back().back() << '\n';
}
