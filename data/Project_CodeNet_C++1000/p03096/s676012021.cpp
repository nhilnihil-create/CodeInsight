#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 20 , mod = 1e9 + 7;
int n , dp[maxn] , c[maxn] , a[maxn];
long long res;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1]) 
		{
			c[a[i]] += dp[i - 1];
			dp[i] = c[a[i]];
		}
		else
		{
			dp[i] = dp[i - 1];
		}
		dp[i] %= mod;
		c[a[i]] %= mod;
	}
	cout << dp[n] << endl;
	return 0;
}