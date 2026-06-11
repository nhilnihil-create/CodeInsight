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
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
#define vvec vector<vector<ll>>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll ac(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }

int main()
{
	int H, W;
	cin >> H >> W;
	deque<pair<int, int>> path;
	vector<vector<int>> d(H, vector<int>(W));
	vector<string> A(H);
	rep(i, 0, H)cin >> A[i];
	rep(i, 0, H) {
		rep(i2, 0, W) {
			if (A[i][i2] == '#')path.push_back({ i, i2 });
		}
	}
	int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
	int ans = 0;
	while (path.size()) {
		auto it = path.front();
		path.pop_front();
		rep(i, 0, 4) {
			int tx = it.second + dx[i], ty = it.first + dy[i];
			if (tx < 0 || tx >= W || ty < 0 || ty >= H)continue;
			if (A[ty][tx] == '.' && d[ty][tx] == 0) {
				d[ty][tx] = d[it.first][it.second] + 1;
				ans = max(ans, d[ty][tx]);
				path.push_back({ty, tx});
			}
		}
		/*rep(i, 0, H) {
			rep(i2, 0, W) {
				if (d[i][i2])printf("%d", d[i][i2]);
				else printf("%c", A[i][i2]);
			}
			puts("");
		}
		puts("");*/
	}
	printf("%d\n", ans);
	return 0;
}
