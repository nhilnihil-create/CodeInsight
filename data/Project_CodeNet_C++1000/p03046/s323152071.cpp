#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
#define sz(v) (ll)(v).size()
#define fi first
#define se second
#define ln '\n'
const ll MOD = 1e9 + 7;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }

void solve(int tc)
{
	ll m, k;
	cin >> m >> k;
	ll lim = (1ll << m);
	if (k >= lim)
	{
		cout << -1 << ln;
		return;
	}
	if (m == 0)
		cout << "0 0" << ln;
	else if (m == 1)
	{
		if (k == 0)
			cout << "0 0 1 1" << ln;
		else
			cout << -1 << ln;
	}
	else
	{
		if (k == 0)
		{
			for (int i = 0; i < (1ll << m); i++)
				cout << i << ' ' << i << ' ';
			cout << ln;
			return;
		}
		s64 elt;
		for (ll i = 0; i < (1ll << m); i++)
			elt.insert(i);
		v64 ans;
		//each time build two segments of length four
		while (sz(elt))
		{
			ll e = *elt.begin();
			elt.erase(e);
			ll e_ = k ^ e;
			elt.erase(e_);
			ll z = *elt.begin();
			elt.erase(z);
			ans.push_back(z);
			ans.push_back(e);
			ans.push_back(e_);
			ans.push_back(z);
			ll z_ = z ^ k;
			elt.erase(z_);
			ans.push_back(z_);
			ans.push_back(e_);
			ans.push_back(e);
			ans.push_back(z_);
		}
		for (ll x : ans)
			cout << x << ' ';
		cout << ln;
	}
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
