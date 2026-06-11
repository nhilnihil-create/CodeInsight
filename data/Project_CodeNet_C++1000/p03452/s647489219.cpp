// In The Name Of Allah
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e12;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
const ll mod = 1e9 + 7;
 
 
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const ll M = 10 + 10;
const ll N = 200 * 1000 + 10;

vector <pii> adj[N];
vector <pair <int, pii> > edge;
bool ok = true, vis[N];
ll dist[N];


void dfs(int v)
{
	vis[v] = 1;
	for (auto e : adj[v])
	{
		int u = e.second, w = e.first;
		if(vis[u])
			continue;
		dist[u] = dist[v] + w;
		dfs(u);
	}
}

int main()
{
	faster();
	int n, m;
	cin >> n >> m;
//	cout << "DEBUG\n";
	for (int i = 0; i < m; i++)
	{
		int v, u, w;
		cin >> v >> u >> w;
		v--, u--;
		adj[v].push_back({w, u});
		adj[u].push_back({-w, v});
		edge.push_back({w, {v, u}});
	}
	for (int i = 0; i < n; i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
//	cout << "DEBUG\n";
	for (auto e : edge)
	{
		int v = e.second.first, u = e.second.second, w = e.first;
		if(dist[v] - dist[u] != -w)
			ok = false;
	}
	if(ok)
		cout << "Yes\n";
	else
		cout << "No\n";
}