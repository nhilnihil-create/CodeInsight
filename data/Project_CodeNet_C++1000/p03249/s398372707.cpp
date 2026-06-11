#include <bits/stdc++.h>
#define fail return (cout << -1 << endl), 0
#define ll long long

using namespace std;

int n;
map<ll, int> f;
ll dis[100010], rdis[100010];
int sz[100010];

struct Edge {
	int to, next;
}es[200010];
int first[100010], te = 0;

void addE(int a, int b)
{
	te++;
	es[te].to = b;
	es[te].next = first[a];
	first[a] = te; 
}

void dfs(int p, int fa)
{
	if (p != 1) rdis[p] = rdis[fa] + 1;
	for (int e = first[p]; e; e = es[e].next)
	{
		int to = es[e].to;
		if (to == fa) continue;
		dfs(to, p); 
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> dis[i];
		f[dis[i]] = i;
		sz[i] = 1;
	}
	int cnt = 0;
	for (map<ll, int>::reverse_iterator it = f.rbegin(); it != f.rend(); it++)
	{
		int v = it->second, u = f[it->first + 2 * sz[v] - n];
		if (!u || u == v) fail;
		addE(u, v); addE(v, u);
		sz[u] += sz[v];
		if (++cnt == n - 1) break;
	}
	dfs(1, 0);
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum += rdis[i];
	if (sum != dis[1]) fail;
	for (int i = 1; i <= n; i++)
		for (int e = first[i]; e; e = es[e].next)
		{
			if (e & 1) continue;
			cout << i << ' ' << es[e].to << endl;
		}
	return 0;
}
