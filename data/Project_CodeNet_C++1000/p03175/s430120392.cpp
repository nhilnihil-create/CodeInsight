#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define sz 100100

ll dp[sz][2];

inline ll mul(ll a, ll b)
{
	a = ((a % MOD) + MOD) % MOD;
	b = ((b % MOD) + MOD) % MOD;
	return (a * b) % MOD;
}

inline ll add(ll a, ll b)
{
	a = ((a % MOD) + MOD) % MOD;
	b = ((b % MOD) + MOD) % MOD;
	return (a + b) % MOD;
}

vector<int>adj[sz];

ll dfs(int rt, bool st, int par)
{

	if (adj[rt].size() == 1 && adj[rt][0] == par)
	{
		if (st)
			return 2;
		return 1;
	}

	ll &ans = dp[rt][st];
	if (ans != -1)
		return ans;

	ans = 1;

	for (auto it : adj[rt])
	{
		if (it == par)
			continue;
		ans = mul(ans, dfs(it, 1, rt));
	}

	if (st)
	{
		ll ans2 = 1;
		for (auto it : adj[rt])
		{
			if (it == par)
				continue;
			ans2 = mul(ans2, dfs(it, 0, rt));
		}
		ans = add(ans, ans2);
	}

	return ans;

}

int main()
{

	memset(dp, -1, sizeof(dp));

	int n, a, b;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d", &a); scanf("%d", &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	cout << dfs(1, 1, -1);



	return 0;
}