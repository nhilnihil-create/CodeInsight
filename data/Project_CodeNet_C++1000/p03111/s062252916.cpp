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
vector<int> l;
int N, A, B, C;
int dfs(int cur, int a, int b, int c) {
	if (cur == N) {
		if (a * b * c > 0)return abs(A - a) + abs(B - b) + abs(C - c) - 30;
		else return INF;
	}
	int cost = INF;
	cost = min(cost, dfs(cur + 1, a, b, c));
	cost = min(cost, dfs(cur + 1, a + l[cur], b, c) + 10);
	cost = min(cost, dfs(cur + 1, a, b + l[cur], c) + 10);
	cost = min(cost, dfs(cur + 1, a, b, c + l[cur]) + 10);
	return cost;
}
int main()
{
	cin >> N >> A >> B >> C;
	l.resize(N);
	rep(i, 0, N)cin >> l[i];
	printf("%d\n", dfs(0,0,0,0));
	return 0;
}