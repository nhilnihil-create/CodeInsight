#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <ctime>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD7 = 1000000007;

ll bpow(ll a, ll d, ll mod) { if (d == 0) return 1; ll t = bpow(a, d / 2, mod); t = (t * t) % mod; if (d & 1) t = (t * a) % mod; return t; }
ll bpow(ll a, ll d) { if (d == 0) return 1; ll t = bpow(a, d / 2); t = (t * t); if (d & 1) t = (t * a); return t; }
ll gcd(ll a, ll b) { while (a && b) if (a > b) a %= b; else b %= a; return a + b; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll C(ll n, ll k) { ll res = 1; for (int i = 1; i <= k; ++i) res = res * (n - k + i) / i; return res; }
ll C(ll n, ll k, ll mod) { ll u = 1, d = 1; for (int i = 2; i <= n; ++i) u = (u * i) % mod; int x = max(k, n - k), z = min(k, n - k); for (int i = 2; i <= x; ++i) { d = (d * i) % mod; if (i <= z) d = (d * i) % mod; } d = bpow(d, mod - 2, mod); ll res = (u * d) % mod; return res; }

ll ans(vector<pair<ll, ll>> v, ll n, ll c)
{
	vector<ll> suf(n);
	suf.back() = 2 * (v.back().first - c) + v.back().second;
	for (int i = n - 2; i >= 0; --i)
		suf[i] = suf[i + 1] + 2 * (v[i].first - v[i + 1].first) + v[i].second;

	for (int i = n - 2; i >= 0; --i)
		suf[i] = max(suf[i + 1], suf[i]);

	ll ans = 0LL;
	if (n > 1)
		ans = max(ans, suf[1] - v[0].first + v[0].second);

	ll cur = v[0].second - v[0].first;
	for (int i = 1; i < n - 1; ++i)
	{
		cur += v[i - 1].first - v[i].first + v[i].second;
		ans = max(max(ans, cur + suf[i + 1]), cur);
	}

	ll sum = 0;
	for (int i = 0; i < n; ++i)
		sum += v[i].second;
	ans = max(max(ans, sum - v.back().first), sum - c + v.front().first);
	return ans;
}

void solve()
{
	ll n, c; cin >> n >> c;
	vector<pair<ll, ll>> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;

	ll res = ans(v, n, c);
	for (int i = 0; i < n; ++i)
		v[i].first = c - v[i].first;
	reverse(v.begin(), v.end());
	res = max(res, ans(v, n, c));
	cout << res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif
	solve();
	return 0;
}