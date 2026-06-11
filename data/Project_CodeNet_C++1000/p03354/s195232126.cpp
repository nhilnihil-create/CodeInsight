#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Vec = vector<int>;
using Graph = vector<Vec>;
#define INF 1000000007
#define MOD 1000000007
#define SEP " "

class UnionFind
{
	vector<int> parent;

	public:

	UnionFind(int n)
	{
		parent.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int x)
	{
		if (parent[x] == x)
			return (x);
		else
			return (parent[x] = find(parent[x]));
	}

	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return ;
		parent[x] = y;
	}

	bool same(int x, int y)
	{
		return (find(x) == find(y));
	}
};

int		main(void)
{
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
	}
	UnionFind uft(n);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		uft.unite(x, y);
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (uft.same(i, p[i]))
			count++;
	}
	cout << count << endl;
}
