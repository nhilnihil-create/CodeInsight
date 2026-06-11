#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph(51,vector<int> (51,0));
int n;

void dfs(int s,vector<bool> &visit)
{
	visit[s]=true;
	for (int i=0;i<n+1;i++)
	{
		if (!visit[i] && graph[s][i])
		{
			dfs(i,visit);
		}
	}
	return ;
}

int main()
{
	int m;cin >> n >> m;
	int u,v;
	vector<pair<int,int>> edge(m);
	for (int i=0;i<m;i++)
	{
		cin >> u >>v;
		graph[u][v]++;
		graph[v][u]++;
		edge[i].first=u;
		edge[i].second=v;
	}
	int ans=0;
	for (int i=0;i<m;i++)
	{
		u=edge[i].first;
		v=edge[i].second;
		graph[u][v]--;
		graph[v][u]--;
		vector<bool> visit(n+1,false);
		dfs(1,visit);
		for (int j=1;j<n+1;j++)
		{
			if (!visit[j])
			{
				ans++;
				break;
			}
		}
		graph[u][v]++;
		graph[v][u]++;
	}
	cout << ans << endl;
	return 0;
}