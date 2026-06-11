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
ll co(ll n, ll k) { ll a = 1; rep(i, 1ll, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }

int main(void) {
	int h, w, t = 0;
	cin >> h >> w;
	vector<string> s(h);
	vector<vector<int>> c(h, vector<int>(w, -1));
	rep(i, 0, h)cin >> s[i];
	deque<pair<int, int>> path;
	path.push_back({0,0});
	c[0][0] = 1;
	rep(i, 0, h)rep(i2, 0, w)t += (s[i][i2] == '.');
	while (path.size()) {
		auto it = path.front();
		int x = it.first, y = it.second;
		path.pop_front();
		const int dx[4] = { 0, 0, 1 ,-1 }, dy[4] = {1, -1, 0, 0};
		rep(i, 0, 4) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx < 0 || tx >= w || ty < 0 || ty >= h)continue;
			if (s[ty][tx] == '.') {
				if (c[ty][tx] == -1)path.push_back({ tx, ty }), c[ty][tx] = c[y][x] + 1;
			}
		}
	}
	if (c[h - 1][w - 1] == -1)puts("-1");
	else printf("%d\n", t - c[h-1][w-1]);
	return 0;
}
