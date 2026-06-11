// In The Name Of Allah
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e12;
typedef long long ll;
typedef pair <ll, ll> pii;
const ll mod = 1e9 + 7;
 
 
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const ll M =  500 + 10;
const ll N = 100 * 1000 + 10;

vector <int> adj[N];
set <int> g[N];
bool mark[N];
ll par[N];

void dfs(int v)
{
	mark[v] = 1;
	vector <int> ver;
	for (auto u : adj[v])
	{
		if(!mark[u])
		{
			if(g[u].size() == 1)
				par[u] = v + 1, ver.push_back(u);
			else
			{
				g[u].erase(g[u].find(v));
			}
		}
	}
	for (auto u : ver)
		dfs(u);
}

int main()
{
	faster();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m + n - 1; i++)
	{
		int v, u;
		cin >> v >> u;
		v--, u--;
		adj[v].push_back(u);
		g[u].insert(v);
	}
	int root;
	for (int i = 0; i < n; i++)
	{
		if(g[i].empty())
		{
			root = i;
		}
	}
	dfs(root);
	par[root] = 0;
	for (int i = 0; i < n; i++)
	{
		cout << par[i] << "\n";
	}
}