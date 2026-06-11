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
	int n, k; cin >> n >> k;
	vector<ll> a(n + 1); rep(i, n)cin >> a[i + 1];
	rep(i, n)a[i + 1] += a[i];
	vector<ll> v;
	rep(i, n)for (int j = i + 1; j <= n; ++j)v.push_back(a[j] - a[i]);
	sort(all(v), greater<ll>());
	ll d = 1;
	while (d << 1 < v[0])d = d << 1;
	ll mask = d - 1;
	ll res = 0;
	while (d > 0)
	{
		res = res << 1;
		vector<ll> ok, ng;
		for (ll x : v)
		{
			ng.push_back(x&mask);
			if (x&d)ok.push_back(x&mask);
		}
		if (ok.size() >= k)
		{
			v = ok;
			res += 1;
		}
		else v = ng;
		d = d >> 1;
		mask = mask >> 1;
	}
	cout << res << endl;
}