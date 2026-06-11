#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;
vector<pair<int, int>> DP;
const int inf = (int)1e9 + 7;

// dfs on a tree
void dfs(int i, int p)
{
	// visit i, node processing is based on its children
	// processing should be after all children has been visited
	// cout << "visiting " << i << endl;
	long long n1 = 1, n2 = 1;
	for (auto x : adj[i])
	{
		if (x == p) // add parents to avoid stuck in loops (no visited array here)
			continue;
		dfs(x, i);
		// if all children are white, i can be both while and black
		// if one of the children is black, i has to be white
		// update DP here, first is when number of different subtree if this node is white
		// second is the number of different subtree if this node is black
		n1 *= (long long) (DP[x].first + DP[x].second);
		n2 *= DP[x].first;
		n1 %= inf;
		n2 %= inf;
	}
	DP[i].first = n1;
	DP[i].second = n2;
}

int main()
{
	cin >> n;
	adj.resize(n + 1);
	DP.resize(n + 1);

	// bottom up DP for trees
	int a, b;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 1);
	cout << (DP[1].first + DP[1].second)%inf << endl;
}