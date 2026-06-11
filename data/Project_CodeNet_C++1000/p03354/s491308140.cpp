#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define cer(x) cerr << x <<endl
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(ALL(x), val), x.end())
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll mod = 1e9 + 7;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }

struct UnionFind
{
	vector<int> par;
	vector<int> rank;

	UnionFind(int n) : par(n), rank(n)
	{
		for (int i = 0; i < n; i++)
		{
			par[i] = i;
			rank[i] = 0;
		}
	}
	int root(int x)
	{
		if (par[x] == x)
		{
			return x;
		}
		else
		{
			return par[x] = root(par[x]);
		}
	}
	void unite(int x, int y)
	{
		int rx = root(x);
		int ry = root(y);
		if (rx == ry)return;
		if (rank[rx] < rank[ry])
		{
			par[rx] = ry;
		}
		else
		{
			par[ry] = rx;
			if (rank[rx] == rank[ry])rank[rx]++;
		}
	}
	bool same(int x, int y)
	{
		return root(x) == root(y);
	}
};


int main()
{
	int n, m; cin >> n >> m;
	vector<int>p(n);
	rep(i, n)
	{
		cin >> p[i];
		p[i]--;
	}
	UnionFind uf(n);
	rep(i, m)
	{
		int x, y; cin >> x >> y;
		x--; y--;
		uf.unite(x, y);
	}
	int ans = 0;
	rep(i, n)
	{
		if (uf.same(p[i], i))ans++;
	}
	co(ans);
	return 0;
}
