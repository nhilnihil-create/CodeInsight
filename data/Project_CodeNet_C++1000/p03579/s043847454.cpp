#include <bits/stdc++.h>
using namespace std;

static const int MAX_N = 1e5;
vector<int> g[MAX_N];
int color[MAX_N];
int n, m;

bool dfs(int u, int c)
{
	color[u] = c;
	for (int v : g[u])
	{
		if (color[v] == c)
		{
			return false;
		}
		else if (color[v] == 0 && !dfs(v, -c))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	if (dfs(0, 1))
	{
		int64_t b = 0, w = 0;
		for (int i = 0; i < n; ++i)
		{
			if (color[i] == 1)
			{
				++b;
			}
			else if (color[i] == -1)
			{
				++w;
			}
		}
		cout << b * w - m << endl;
	}
	else
	{
		cout << 1LL * n * (n - 1) / 2 - m << endl;
	}
}