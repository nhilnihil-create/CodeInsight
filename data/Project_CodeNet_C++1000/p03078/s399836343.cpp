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
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<v64> arr(3, v64());
	arr[0].assign(x, 0);
	arr[1].assign(y, 0);
	arr[2].assign(z, 0);
	for (int i = 0; i < x; i++)
		cin >> arr[0][i];
	for (int i = 0; i < y; i++)
		cin >> arr[1][i];
	for (int i = 0; i < z; i++)
		cin >> arr[2][i];
	for (int i = 0; i < 3; i++)
		sort(arr[i].begin(), arr[i].end());
	set<pair<ll, v32>> Q;
	v32 temp = {x - 1, y - 1, z - 1};
	Q.insert({arr[0][x - 1] + arr[1][y - 1] + arr[2][z - 1], temp});
	while (k--)
	{
		pair<ll, v32> p = *(Q.rbegin());
		db(p.fi, p.se);
		cout << p.fi << ln;
		Q.erase(p);
		int idx[3];
		idx[0] = p.se[0], idx[1] = p.se[1], idx[2] = p.se[2];
		for (int j = 0; j < 3; j++)
		{
			ll res = p.fi;
			int z = idx[j];
			z--;
			if (z < 0)
				continue;
			res -= arr[j][z + 1];
			res += arr[j][z];
			p.se[j]--;
			Q.insert({res, p.se});
			p.se[j]++;
		}
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
