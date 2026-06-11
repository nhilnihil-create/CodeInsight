#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n, i, j, u, v, vis[100001] = {0}, par[100001] = {0}, dp[100001][2] = {0};
vector<long long>adj[100001];

void pardfs(long long x, long long p)
{
	vis[x] = 1;
	par[x] = p;
	for(long long y = 0; y < adj[x].size(); y++)
	{
		if(!vis[adj[x][y]])
		{
			pardfs(adj[x][y], x);
		}
	}
}

void dpdfs(long long x)
{
	vis[x] = 1;
	for(long long y = 0; y < adj[x].size(); y++)
	{
		if(!vis[adj[x][y]])
		{
			dpdfs(adj[x][y]);
		}
	}
	if(adj[x].size() == 1 && x != 1)
	{
		dp[x][0] = dp[x][1] = 1;
	}
	else
	{
		long long m = 1, p = 1;
		for(long long y = 0; y < adj[x].size(); y++)
		{
			if(adj[x][y] != par[x])
			{
				m = ((m % mod) * (dp[adj[x][y]][1] % mod)) % mod;
				p = ((p % mod) * ((dp[adj[x][y]][0] + dp[adj[x][y]][1]) % mod)) % mod;
			} 
		}
		dp[x][0] = m;
		dp[x][1] = p;
	}
}

int main()
{
	cin >> n;
	for(i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	pardfs(1, 0);
	for(i = 0; i <= n; i++)
	{
		vis[i] = 0;
	}
	dpdfs(1);
	if(n == 1)
		cout << 2;
	else
		cout << (dp[1][0] + dp[1][1]) % mod;
	return 0;
}