#include <bits/stdc++.h>
using namespace std;
const int num = 100001;
vector <int> adj[num];
int vis[num],level[num];
void dfs(int cur)
{
	vis[cur] = 1;
	for(int i=0;i<adj[cur].size();i++)
	{
		int child = adj[cur][i];
		if(!vis[child])
		{
			dfs(child);
		}
	}
	for(int i=0;i<adj[cur].size();i++)
	{
		int child = adj[cur][i];
		level[cur] = max(level[cur],1+level[child]);
	}
}
int main()
{
	int n,m,x,y;
	cin >> n >> m;
	for(int i=0;i<m;i++)
		cin >> x >> y,adj[x].push_back(y);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
			dfs(i);
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
		ans = max(ans,level[i]);
	cout << ans << "\n";
}
	
