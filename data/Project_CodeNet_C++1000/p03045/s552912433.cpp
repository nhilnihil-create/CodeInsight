#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
	vector<int> par;
	vector<int> rank;
	vector<int> sizes;

	UnionFind(int n) : par(n), rank(n, 0), sizes(n, 1)
	{
		for (int i = 0; i < n; i++)
			par[i] = i;
	}
	int find(int x)
	{
		if (par[x] == x) {
			return x;
		} else {
			return (par[x] = find(par[x]));
		}
	}
	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return;

		if (rank[x] < rank[y]) {
			par[x] = y;
			sizes[y] += sizes[x];
		} else {
			par[y] = x;
			sizes[x] += sizes[y];
			if (rank[x] == rank[y])
				rank[x]++;
		}
	}
	bool same(int x, int y)
	{
		return (find(x) == find(y));
	}
	int size(int x)
	{
		return sizes[find(x)];
	}
};
int main(void)
{
	int n, m;
	cin >> n >> m;
	UnionFind uf(n);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		uf.unite(x, y);
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(uf.find(i));
	}
	cout << s.size() << endl;
	return 0;
}