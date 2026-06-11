#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll curr_cost(vector<ll>&slimes, ll i, ll j)
{
	ll sum = 0;
	for (ll k = i; k <= j; k++)
	{
		sum += slimes[k];
	}
	return sum;
}
ll min_cost(vector<ll>&slimes, ll i, ll j, vector<vector<ll>>&dp)
{
	if (i >= j)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	ll ans = LLONG_MAX;
	ll cost = curr_cost(slimes, i, j);
	for (ll k = i; k < j; k++)
	{
		ll temp_ans = min_cost(slimes, i, k, dp) + min_cost(slimes, k + 1, j, dp) + cost ;
		ans = min(ans, temp_ans);
	}
	return dp[i][j] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin >> n;
	vector<ll>slimes(n);
	for (ll i = 0; i < n; i++)
	{
		ll d;
		cin >> d;
		slimes[i] = d;
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, -1));
	ll ans = min_cost(slimes, 0, n - 1, dp);
	cout << ans << endl;
	return 0;

}