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

int main()
{
	int N, C, ans = INF;
	cin >> N >> C;
	vector<vector<int>> d(C, vector<int>(C));
	vector<vector<int>> c(N, vector<int>(N));
	rep(i, 0, C)rep(i2, 0, C)cin >> d[i][i2];
	rep(i, 0, N)rep(i2, 0, N)cin >> c[i][i2], c[i][i2]--;
	int sum[3][100] = {0};
	rep(color, 0, C) {
		rep(i, 0, N) {
			rep(i2, 0, N) {
				sum[(i + i2) % 3][color] += d[c[i][i2]][color];
			}
		}
	}
	rep(c0, 0, C) {
		rep(c1, 0, C) {
			if (c1 == c0)continue;
			rep(c2, 0, C) {
				if (c2 == c0 || c2 == c1)continue;
				ans = min(ans, sum[0][c0] + sum[1][c1] + sum[2][c2]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}