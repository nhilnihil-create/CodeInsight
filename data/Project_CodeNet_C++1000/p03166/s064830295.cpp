#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x,y;
	cin >> n >> m;
	vector <int> adj[n+1];
	int out[n+1],in[n+1],vis[n+1];
	memset(vis,0,sizeof(vis));
	memset(out,0,sizeof(out));
	memset(in,0,sizeof(in));
	for(int i=0;i<m;i++)
		cin >> x >> y,adj[x].push_back(y),out[x]++,in[y]++;
	queue <int> q;
	for(int i=1;i<=n;i++)
		if(in[i]==0) q.push(i);
	vector <int> topo_sort;
	while(!q.empty())
	{
		int cur = q.front();
		vis[cur] = 1;
		topo_sort.push_back(cur);
		q.pop();
		for(int j=0;j<adj[cur].size();j++)
		{
			int child = adj[cur][j];
			in[child]--;
			if(in[child]==0)
				q.push(child);
		}
	}
	int dist[n+1];
	int ans = 0;
	memset(dist,0,sizeof(dist));
	for(int i=0;i<topo_sort.size();i++)
	{
		int parent = topo_sort[i];
		for(int j=0;j<adj[parent].size();j++)
		{
			int child = adj[parent][j];
			dist[child] = max(dist[child],dist[parent]+1);
			ans = max(ans,dist[child]);
		}	
	}
	// cout << topo_sort.size() << "\n";
	cout << ans << "\n";
}
