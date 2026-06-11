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
 
const long long N = 100 * 1000 + 5;
vector< pair<long long , long long> > graph[N];
const long long inf = 1000 * 1000 * 1000 * 1000ll * 1000 * 1000;

long long mark[N];
long long place[N];
long long n, m;
bool check = true;

void dfs(long long v)
{
	mark[v] = true;
	for (long long i = 0; i < graph[v].size(); i++)
	{
		long long u = graph[v][i].first;
		long long w = graph[v][i].second;
		if (place[u] == inf)
		{
			place[u] = place[v] + w;
			dfs(u);
		}
		else
		{
			if (place[u] != place[v] + w)
			{
				check = false;
			}
		}
	}
}


int main() 
{
	cin >> n >> m;
	for (long long i = 0; i < m; i++)
	{
		long long u, v, w;
		cin >> u >> v >> w;
		graph[u - 1].push_back({v - 1, w});
		graph[v - 1].push_back({u - 1, -w});
	}
	for (long long i = 0; i < n; i++)
	{
		place[i] = inf;
	}
	for (long long i = 0; i < n; i++)
	{
		if (!mark[i])
		{
			place[i] = 0;
			dfs(i);
		}
	}
	if (check)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}

























