#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include <iomanip>

using namespace std;

const int N = 100 * 1000;
int in[N];
int par[N];
int mark[N];
int n, m, root;
vector<int> graph[N];
void dfs(int v)
{
	mark[v] = true;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int u = graph[v][i];
		in[u]--;
		
	}
	for (int i = 0; i < graph[v].size(); i++)
	{
		int u = graph[v][i];
		if (!mark[u] && in[u] == 0)
		{
			par[u] = v + 1;
			dfs(u);
		}
	}
}


int main() 
{
	cin >> n >> m;
	for (int i = 0; i < n - 1 + m; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		in[v - 1]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (in[i] == 0)
		{
			root = i;
		}
	}
	//cout << root << endl;
	par[root] = 0;
	dfs(root);
	for (int i = 0; i < n; i++)
	{
		cout << par[i] << endl;
	}
}

























