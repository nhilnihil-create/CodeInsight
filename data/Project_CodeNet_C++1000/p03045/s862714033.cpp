#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

struct UnionFind
{
	vector<int> uni;

	UnionFind(int n) : uni(n, -1){}

	int root(int a)
	{
		if (uni[a] < 0) return a;	
		return uni[a] = root(uni[a]);
	}

	bool connect(int a, int b)
	{
		a = root(a);
		b = root(b);
		if (a == b) return false;
		if (uni[a] > uni[b])
		{
			a ^= b;
			b ^= a;
			a ^= b;
		}
		uni[a] = uni[a] + uni[b];
		uni[b] = a;
		return true;
	}

	bool isConnect(int a, int b)
	{
		return root(a) == root(b);
	}

	int size(int a)
	{
		return -uni[root(a)];
	}
};

signed main(void)
{
	int n, m, cnt;
	cin >> n >> m;
	vector<bool> check(n, false);
	UnionFind uf(n);
	rep(i, m)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		if (!uf.isConnect(x, y)) uf.connect(x, y);
	}
	cnt = 0;
	rep(i, n)
	{
		int p = uf.root(i);
		if (!check[p])
		{
			cnt++;
			check[p] = true;
		}
	}
	cout << cnt << endl;
	return 0;
}
