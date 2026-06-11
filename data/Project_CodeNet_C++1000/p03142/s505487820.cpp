#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <bitset>
#include <fstream>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()

#pragma region UnionFind
struct UnionFind
{
	vector<int> par;

	UnionFind(int n) : par(n, -1) {}
	void init(int n) { par.assign(n, -1); }

	int root(int x)
	{
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y)
	{
		return root(x) == root(y);
	}

	bool merge(int x, int y)
	{
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x)
	{
		return -par[root(x)];
	}
};
#pragma endregion
#pragma region GCD
int gcd(int a, int b)
{
	if (a%b == 0)return b;
	return gcd(b, a%b);
}
#pragma endregion
#pragma region chmin
template<class T> inline bool chmin(T& a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma region chmax
template<class T> inline bool chmax(T& a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma endregion

vector<vector<int>> to(100005), ot(100005);
vector<int> order;
vector<bool> seen(100005);

void dfs(int now)
{
	seen[now] = true;
	for (auto next : to[now])
	{
		if (seen[next])continue;
		dfs(next);
	}
	order.push_back(now);
}

int main()
{
	int n, m; cin >> n >> m;
	rep(i, n + m - 1)
	{
		int a, b; cin >> a >> b;
		to[a].push_back(b);
		ot[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (seen[i])continue;
		dfs(i);
	}
	reverse(all(order));
	vector<int> depth(n + 1);
	rep(i, n)depth[order[i]] = i;
	vector<int> res(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (ot[i].size() == 0)continue;
		int mndepth = -1;
		int parent = 0;
		for (int p : ot[i])
		{
			if (chmax(mndepth, depth[p]))
			{
				parent = p;
			}
		}
		res[i] = parent;
	}
	for (int i = 1; i <= n; ++i)cout << res[i] << endl;
}