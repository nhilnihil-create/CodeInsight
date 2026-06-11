#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0)
//#define MULTI_TEST
//#define GOOGLE
#ifdef LOCAL
#include "debugger.h"
#else
#define db(...)
#endif
#define ll long long
#define v32 vector<int>
#define v64 vector<ll>
#define s32 set<int>
#define s64 set<ll>
#define p32 pair<int, int>
#define p64 pair<ll, ll>
#define fi first
#define se second
#define ln '\n'
const ll MOD = 1e9 + 7;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }

struct dsu
{
	vector<int> par, sz;
	int comp;
	dsu(int n)
	{
		comp = n;
		par.assign(n + 1, -1);
		iota(par.begin(), par.end(), 0);
		sz.assign(n + 1, 1);
	}
	int find(int x)
	{
		if (x != par[x])
			return (par[x] = find(par[x]));
		return par[x];
	}
	bool unite(int x, int y)
	{
		int a = find(x);
		int b = find(y);
		if (a != b)
		{
			if (sz[a] < sz[b])
			{
				par[a] = b;
				sz[b] += sz[a];
			}
			else
			{
				par[b] = a;
				sz[a] += sz[b];
			}
			comp--;
			return true;
		}
		else
			return false;
	}
	int countSet()
	{
		return comp;
	}
	int sizeOfSet(int i)
	{
		return sz[find(i)];
	}
};
void solve(int tc)
{
	ll n, m;
	cin >> n >> m;
	dsu D(n);
	vector<p32> arr(m);
	for (int i = 0; i < m; i++)
		cin >> arr[i].fi >> arr[i].se;
	v64 ans(m, 0);
	ans[m - 1] = n * (n - 1) / 2;
	ll curr = ans[m - 1];
	int idx = m - 2;
	for (int i = m - 1; i >= 1; i--)
	{
		int u = arr[i].fi, v = arr[i].se;
		ll x = D.sizeOfSet(u), y = D.sizeOfSet(v);
		db(arr[i], x, y);
		if (D.unite(u, v))
			curr -= x * y;
		ans[idx--] = curr;
	}
	for (ll x : ans)
		cout << x << ln;
	return;
}

int main()
{
#ifndef LOCAL
	FASTIO;
#endif
	int t = 1;
#ifdef LOCAL
	clock_t start, stop;
	start = clock();
#endif
#ifdef MULTI_TEST
	cin >> t;
#endif
	for (int tc = 1; tc < t + 1; tc++)
	{
#ifdef GOOGLE
		cout << "Case #" << tc << ": ";
#endif
		solve(tc);
	}
#ifdef LOCAL
	stop = clock();
	cerr << "Time :" << fixed << setprecision(5) << double(stop - start) / double(CLOCKS_PER_SEC) << "s" << ln;
#endif
	return 0;
}
