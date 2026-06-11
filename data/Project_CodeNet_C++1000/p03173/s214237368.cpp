#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf (1ll<<60)

ll dp[405][405];
ll sum[405][405];

ll solve(std::vector<ll>& v, ll i, ll j)
{
	//base case
	if (i == j)
		return 0;
	//when answer is calculated before
	if (dp[i][j] != -1)
		return dp[i][j];

	//recursive
	ll minCost = inf;//store the minm value
	for (int k = i; k < j; k++)
	{
		minCost = min(minCost, sum[i][j] + solve(v, i, k) + solve(v,  k + 1, j));
	}

	return dp[i][j] = minCost;
}

void preprocess(vector<ll>& v, ll n)
{
	for (int i = 1; i <= n; i++ )
	{
		for (int j = i; j <= n; j++)
		{
			sum[i][j] = v[j] + ((j == i) ? 0 : sum[i][j - 1]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	vector<ll> v(n + 1);//store height of slime

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	preprocess(v, n);

	cout << solve(v, 1, n);
}