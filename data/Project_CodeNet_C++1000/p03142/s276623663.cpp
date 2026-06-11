#include <bits/stdc++.h>

using namespace std;

int n,m;
int p[100001], deg[100001];
vector<int> AdjList[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i=1;i<=n-1+m;i++)
	{
		int u,v;
		cin >> u >> v;
		AdjList[u].push_back(v);
		deg[v]++;	
	}
	queue<int> q;
	for (int i=1;i<=n;i++)
		if (!deg[i])
		{
			q.push(i);
			break;
		}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i=0;i<AdjList[u].size();i++)
		{
			int v = AdjList[u][i];
			deg[v]--;
			if (!deg[v])
			{
				p[v] = u;
				q.push(v);
			}
		}
	}
	for (int i=1;i<=n;i++)
		cout << p[i] << '\n';
}