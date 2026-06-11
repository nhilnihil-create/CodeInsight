#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iostream>
#include <bitset>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define rep2(i, a)for(auto i : a)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x, std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
#define vvec vector<vector<ll>>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll co(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }

vector<ll> s, t;
ll getlen(int c, int sh, ll x) {
	auto target = sh ? s : t;
	ll xx, xx2, d = 0ll;
	auto it = upper_bound(all(target), x);
	if (it == target.end())xx =  1ll << 60;
	else xx = *it;
	if (it == target.begin())xx2 = - 1ll << 60;
	else xx2 = *--it;
	if (abs(xx - x) > abs(xx2 - x))xx = xx2;
	if(c)d = getlen(0, !sh, xx);
	if (d == 1ll << 60)return d;
	return abs(xx - x) + d;
}
int main()
{
	int a, b, q;
	ll x;
	vector<ll> ans;
	cin >> a >> b >> q;
	s.resize(a);
	t.resize(b);
	rep(i, 0, a)cin >> s[i];
	rep(i, 0, b)cin >> t[i];
	s.push_back(1ll << 60);
	s.push_back(-1ll << 60);
	t.push_back(1ll << 60);
	t.push_back(-1ll << 60);
	sort(all(s));
	sort(all(t));
	rep(i, 0, q) {
		cin >> x;
		auto _s = upper_bound(all(s), x);
		auto _t = upper_bound(all(t), x);
		ll v = 1ll << 60, x1 = *_s, x2 = *--_s, y1 = *_t, y2 = *--_t;
		v = min(v, abs(x1 - x) + abs(y1 - x1));
		v = min(v, abs(x1 - x) + abs(y2 - x1));
		v = min(v, abs(x2 - x) + abs(y1 - x2));
		v = min(v, abs(x2 - x) + abs(y2 - x2));
		v = min(v, abs(x1 - y1) + abs(y1 - x));
		v = min(v, abs(x1 - y2) + abs(y2 - x));
		v = min(v, abs(x2 - y1) + abs(y1 - x));
		v = min(v, abs(x2 - y2) + abs(y2 - x));
		ans.push_back(v);
	}
	rep2(v, ans)printf("%lld\n", v);
	return 0;
}