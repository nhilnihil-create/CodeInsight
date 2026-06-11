#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll num_of_ways(vector<ll>&capacity, ll n, ll k)
{
	vector<vector<ll>>dp(n + 2, vector<ll>(k + 2));
	for (ll j = 0; j <= k; j++)
	{
		if (j > capacity[1])
			dp[1][j] = 0;
		else
			dp[1][j] = 1;
	}
	for(ll j=0;j<=k;j++)
	{
		dp[0][j]=0;
	}
	for (ll i = 2; i <= n; i++)
	{
		for (ll j = 0; j <= k; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else if (j - 1 - capacity[i] >= 0)
			{
				//MOD plus isiliye kiya kyunki agar result negative aaya to MOD kaise hoga
				dp[i][j] = (MOD+dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1 - capacity[i]]) % MOD;
			}
			else
			{
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
			}
		}
	}
	return dp[n][k];
}

int main()
{
	ll n;
	cin >> n;
	ll k;
	cin >> k;
	vector<ll>capacity(n + 1);
	for (ll i = 1; i <= n; i++)
	{
		ll d;
		cin >> d;
		capacity[i] = d;
	}
	cout << num_of_ways(capacity, n, k);
	return 0;
}