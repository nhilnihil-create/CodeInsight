#include <bits/stdc++.h>

using namespace std;

int uf[100001];
int parent[100001];
vector <int> adj[100001];
int indegree[100001];
int n,m,a,b;

int find(int x)
{
	if(uf[x] < 0)
	{
		return x;
	}
	return uf[x] = find(uf[x]);
}

bool merge(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x==y)
	{
		return false;
	}
	uf[y] = x;
	return true;
}
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	memset(uf,-1,sizeof(uf));
	cin >> n >> m;
	for(int i=0;i<n+m-1;i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}

	queue <int> que;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
		{
			que.push(i);
		}
	}

	while(!que.empty())
	{
		int now = que.front();
		que.pop();

		for(auto next : adj[now])
		{
			indegree[next]--;
			if(indegree[next]==0)
			{
				if(merge(now,next))
				{
					parent[next] = now;
				}				
				que.push(next);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout << parent[i] << '\n';
	}
	return 0;	
}