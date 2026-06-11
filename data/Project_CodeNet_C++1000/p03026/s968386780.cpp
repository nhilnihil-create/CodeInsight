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


int main()
{
	int n; cin >> n;
	vector<vector<int>> v(n);
	int t = 0;
	rep(i, n - 1)
	{
		int a, b; cin >> a >> b;
		--a, --b;
		v[a].push_back(b);
		v[b].push_back(a);
		if (v[a].size() > 1)t = a;
	}
	vector<int> c(n); rep(i, n)cin >> c[i];
	sort(all(c), greater<int>());
	vector<bool> used(n);
	queue<int> q;
	q.push(t);
	used[t] = true;
	vector<int> res(n);
	res[t] = c[0];
	int i = 1;
	int s = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int next : v[now])
		{
			if (used[next])continue;
			used[next] = true;
			res[next] = c[i];
			s += c[i];
			++i;
			q.push(next);
		}
	}
	cout << s << endl;
	rep(i, n)cout << res[i] << " ";

}