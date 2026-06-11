#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n, i, k, j, a[100001] = {0}, s = 0, dp[100001] = {0}, sum[100001][2] = {0};
int main()
{
	cin >> n >> k;
	for(i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(i = 0; i <= a[0]; i++)
	{
		sum[i][0] = 1 + i;
		dp[i] = 1;
	}
	s = a[0];
	for(i = a[0] + 1; i <= k; i++)
		sum[i][0] = sum[a[0]][0];
	for(i = 1; i < n; i++)
	{
		s += a[i];
		sum[0][i % 2] = 1;
		sum[0][1 - (i % 2)] = 1;
		long long x = 1 - (i % 2);
		for(j = 1; j <= min(k, s); j++)
		{
			dp[j] = ((sum[j - 1][x] % mod) + (dp[j] % mod)) % mod;
			if(j > a[i])
			{
				dp[j] = ((dp[j] % mod) - (sum[j - a[i] - 1][x] % mod) + mod + mod) % mod;
			}
			sum[j][i % 2] = ((sum[j - 1][i % 2] % mod) + (dp[j] % mod)) % mod;
		}
		for(int g = s + 1; g <= k; g++)
			sum[g][i % 2] = sum[s][i % 2];
	}
	cout << dp[k];
	return 0;
}