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
	int n;
	cin >> n;
	v32 arr(n, 0);
	v32 left(n, 0), right(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			left[i] = arr[i];
			right[n - i - 1] = arr[n - i - 1];
		}
		else
		{
			left[i] = __gcd(left[i - 1], arr[i]);
			right[n - i - 1] = __gcd(right[n - i], arr[n - i - 1]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			ans = max(ans, right[i + 1]);
		else if (i == n - 1)
			ans = max(ans, left[i - 1]);
		else
			ans = max(ans, __gcd(left[i - 1], right[i + 1]));
	}
	cout << ans << ln;
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
