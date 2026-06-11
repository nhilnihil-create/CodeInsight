#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;


ll solve(ll arr[], ll n, ll k)
{
	ll dp[n + 1][k + 1];

	for (ll i = 0; i <= k; i++)
		dp[1][i] = (i <= arr[1]) ? 1 : 0;

	for (ll i = 2; i <= n; i++)
	{
		for (ll j = 0; j <= k; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = (mod + dp[i][j - 1] + dp[i - 1][j] - ((j - arr[i] - 1) >= 0 ? dp[i - 1][j - arr[i] - 1] : 0)) % mod;
		}
	}

	return dp[n][k];
}

int main()
{

	ll n, k;

	cin >> n >> k;

	ll arr[n + 1];

	for (ll i = 1; i <= n; i++)
		cin >> arr[i];

	cout << solve(arr, n, k);
}
