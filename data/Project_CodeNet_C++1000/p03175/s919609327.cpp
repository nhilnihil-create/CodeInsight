#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

vector < long long > DFS(int node, vector < vector <int> > &adjList, vector <bool> &visited)
{
	visited[node]=true;
	vector < vector < long long > > waysChildren;
	for (auto x: adjList[node])
	{
		if (!visited[x])
		{
			waysChildren.push_back(DFS(x, adjList, visited));
		}
	}
	if (waysChildren.empty()) return {1,1};
	vector < long long > ans={1,1};
	for (auto &x: waysChildren)
	{
		ans[0] = (ans[0]*x[1])%mod;
		ans[1] = (ans[1]*(x[0]+x[1]))%mod;
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector < vector <int> > adjList(n+1);
	for (int i=0; i<n-1; ++i)
	{
		int u,v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	vector < bool > visited(n+1, false);
	// vector < vector <long long> > ways(n+1);
	vector < long long > ans = DFS(1, adjList, visited);
	cout << (ans[0]+ans[1])%mod << "\n";
	return 0;
}