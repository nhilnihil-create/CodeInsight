#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
const int maxn = 4e5 + 20;

int to[maxn] , w[maxn] , val[maxn] , x[maxn] , y[maxn] , z[maxn] , id;

vector<int> adj[maxn];

bool visited[maxn];

void add_edge(int a , int b , int c)
{
	adj[a].pb(id);
	to[id] = b , w[id] = c;
	id++;
}

void dfs(int v)
{
	visited[v] = 1;
	for(auto e : adj[v])
	{
		int u = to[e];
		if(!visited[u])
		{
			val[u] = val[v] + w[e];
			dfs(u);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a , b , c;
		cin >> a >> b >> c;
		a-- , b--;

		x[i] = a , y[i] = b , z[i] = c;

		add_edge(a , b , c);
		add_edge(b , a ,-c);
	}

	for(int i = 0; i < n; i++)
		if(!visited[i])
			dfs(i);

	for(int i = 0; i < m; i++)
		if(val[y[i]] - val[x[i]] != z[i])
			return cout << "No" << endl , 0;

	cout << "Yes" << endl;
}
















