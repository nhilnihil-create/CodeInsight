#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

vector<pair<int, int>> DP;
const int inf = (int)1e9 + 7;

// dfs for tree, no need for visit array 
void dfs(int i, int p) //bottom up approach, you need to visit a child before process for current node
{
	//visit i
	 //cout << " visit " << i << endl;
	long long  prod1 = 1, prod2=1;
	for (auto x : adj[i])
	{
		if (x == p)
			continue;
		dfs(x, i);
		// color i after visiting all its children
		// if any of i's child is black, i has to white
		// if all i's child is white, then i can be black or white
		// if one of the child is black, i has to be white
		prod2 = (prod2 * ((DP[x].first + DP[x].second) % inf)) % inf;
		prod1 = (prod1 * DP[x].second) % inf;
	}
	DP[i].second = prod2;
	DP[i].first = prod1;

}

int main()
{
	cin >> n;
	adj.resize(n);
	int t1, t2;
	// tree n vertex, n-1 edges, no direction
	for (int i = 0; i < n-1; i++)
	{
		cin >> t1>> t2;
		t1--; t2--;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}

	// set value for DP array during tree traverse
	// DP[i] should contain two values: first is number of ways to color subtree of i if i is black
	// 2nd is the number of ways to color if i is white

	DP.resize(n);
	dfs(0, -1);
	cout << (DP[0].first + DP[0].second)%inf << endl;
}