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

int base(v32 arr, v32 lol)
{
	int ans = 1e9;
	do
	{
		int tmp = abs(arr[0] - lol[0]) + abs(arr[1] - lol[1]) + abs(arr[2] - lol[2]);
		ans = min(ans, tmp);
	} while (next_permutation(lol.begin(), lol.end()));
	return ans;
}
void solve(int tc)
{
	int n;
	v32 arr(3, 0);
	cin >> n >> arr[0] >> arr[1] >> arr[2];
	v32 lol(n, 0);
	for (int i = 0; i < n; i++)
		cin >> lol[i];
	int ans = 1e9;
	for (int i = 1; i < (1 << n); i++)
	{
		for (int j = 1; j < (1 << n); j++)
		{
			if ((i & j))
				continue;
			for (int k = 1; k < (1 << n); k++)
			{
				if ((i & k) || (j & k))
					continue;
				v32 work(3, 0);
				int cost = -30;
				for (int l = 0; l < n; l++)
				{
					int t = (1 << l);
					if (i & t)
						work[0] += lol[l], cost += 10;
					if (j & t)
						work[1] += lol[l], cost += 10;
					if (k & t)
						work[2] += lol[l], cost += 10;
				}
				cost += base(work, arr);
				ans = min(ans, cost);
				db(i, j, k, ans);
			}
		}
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
