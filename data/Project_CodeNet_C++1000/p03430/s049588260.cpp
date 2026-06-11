#include<bits/stdc++.h>
using namespace std;

const int N = 3e2 + 10;
int dp[N][N][N];

int main()
{
	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = s.size();
	for (int tool = 1; tool <= n; tool++)
	{
		for (int l = 0; l + tool <= n; l++)
		{
			int r = l + tool - 1;
			if (tool == 1)
			{
				for (int kk = 0; kk <= k; kk++)
				{
					dp[l][r][kk] = 1;
				}
				continue;
			}
			for (int kk = 0; kk <= k; kk++)
			{
				if (kk > tool)
				{
					dp[l][r][kk] = dp[l][r][tool];
					continue;
				}
				if (s[l] == s[r])
				{
					dp[l][r][kk] = 2 + dp[l + 1][r - 1][kk];
					continue;
				}
				if (kk == 0)
				{
					dp[l][r][kk] = max(dp[l + 1][r][kk], dp[l][r - 1][kk]);
					continue;
				}
				dp[l][r][kk] = max({2 + dp[l + 1][r - 1][kk - 1], dp[l + 1][r][kk], dp[l][r - 1][kk]});
			}
		}
	}
	cout << dp[0][n - 1][k];
}
