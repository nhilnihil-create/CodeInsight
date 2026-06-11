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
ll ac(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }

int main()
{
	int n, c, x, x2;
	cin >> n;
	vector<int> a(n), b, b2;
	rep(i, 0, n)cin >> a[i];
	sort(all(a));
	int k = (int)sqrt(a[0]), k2 = (int)sqrt(a[1]);
	rep(i, 1, k + 1) {
		if (a[0] % i == 0) {
			b.push_back(i);
			b.push_back(a[0] / i);
		}
	}
	r_sort(all(b));
	for (auto v : b) {
		c = 0;
		rep(i, 0, n) {
			if (a[i] % v == 0)c++;
		}
		if (c >= n - 1) {
			x = v;
			break;
		}
	}
	rep(i, 1, k2 + 1) {
		if (a[1] % i == 0) {
			b2.push_back(i);
			b2.push_back(a[1] / i);
		}
	}
	r_sort(all(b2));
	for (auto v : b2) {
		c = 0;
		rep(i, 0, n) {
			if (a[i] % v == 0)c++;
		}
		if (c >= n - 1) {
			x2 = v;
			break;
		}
	}
	printf("%d\n", max(x, x2));
	return 0;
}
