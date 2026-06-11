#include<bits/stdc++.h>
using namespace std;
long long dp[401][401] = {0};
long long n, i, j, k, a[401] = {0}, pref[401] = {0};
int main()
{
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> a[i];
		if(i == 0)
			pref[i] = a[i];
		else
			pref[i] = pref[i - 1] + a[i];
	}
	for(i = 2; i <= n; i++)
	{
		for(j = 0; j + i - 1 < n; j++)
		{
			long long mn = 1e18;
			for(k = j; k < j + i - 1; k++)
			{
				if(j > 0)
					mn = min(mn, dp[j][k] + dp[k + 1][j + i - 1] + pref[k] - pref[j - 1] + pref[j + i - 1] - pref[k]);
				else
					mn = min(mn, dp[j][k] + dp[k + 1][j + i - 1] + pref[k] + pref[j + i - 1] - pref[k]);
			}
			dp[j][i + j - 1] = mn;
		}
	}
	cout << dp[0][n - 1];
	return 0;
}