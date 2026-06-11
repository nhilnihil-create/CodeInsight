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
#define sz(v) (ll)(v).size()
#define fi first
#define se second
#define ln '\n'
const ll MOD = 1e9 + 7;
inline ll add(ll a, ll b, ll m) { return (((a % m + b % m) % m + m) % m); }
inline ll mul(ll a, ll b, ll m) { return (((a % m * b % m) % m + m) % m); }
ll getDistOpp(ll x, ll y, ll z)
{
	return min(abs(y - x), abs(z - x)) + abs(y - z);
}
ll getDistRight(ll x, ll y, ll z)
{
	return abs(x - max(y, z));
}
ll getDistLeft(ll x, ll y, ll z)
{
	return abs(x - min(y, z));
}
void solve(int tc)
{
	int a, b, q;
	cin >> a >> b >> q;
	v64 shrine(a, 0), temple(b, 0);
	for (int i = 0; i < a; i++)
		cin >> shrine[i];
	for (int i = 0; i < b; i++)
		cin >> temple[i];
	while (q--)
	{
		ll x;
		cin >> x;
		ll ans = 1e18;
		int s_l = -1, s_r = -1, t_l = -1, t_r = -1;
		//get closest shrine on left
		int idx = upper_bound(shrine.begin(), shrine.end(), x) - shrine.begin();
		idx--;
		if (idx >= 0)
			s_l = idx;
		//get closest shrine on right
		idx = lower_bound(shrine.begin(), shrine.end(), x) - shrine.begin();
		if (idx != sz(shrine))
			s_r = idx;
		//get closest temple on left
		idx = upper_bound(temple.begin(), temple.end(), x) - temple.begin();
		idx--;
		if (idx >= 0)
			t_l = idx;
		//get closest temple on right
		idx = lower_bound(temple.begin(), temple.end(), x) - temple.begin();
		if (idx != sz(temple))
			t_r = idx;
		db(x, s_l, s_r, t_r, t_l);
		if (s_l != -1 && t_r != -1)
			ans = min(ans, getDistOpp(x, shrine[s_l], temple[t_r]));
		if (s_r != -1 && t_l != -1)
			ans = min(ans, getDistOpp(x, shrine[s_r], temple[t_l]));
		if (s_r != -1 && t_r != -1)
			ans = min(ans, getDistRight(x, shrine[s_r], temple[t_r]));
		if (s_l != -1 && t_l != -1)
			ans = min(ans, getDistLeft(x, shrine[s_l], temple[t_l]));
		cout << ans << ln;
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
