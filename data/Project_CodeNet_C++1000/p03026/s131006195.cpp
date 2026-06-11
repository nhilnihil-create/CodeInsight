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
	int N, a, b, p = 0;
	ll M = 0;
	cin >> N;
	vector<vector<int>> G(N);
	vector<int> c(N), score(N);
	rep(i, 0, N - 1) {
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i, 0, N)cin >> c[i];
	r_sort(all(c));
	vector<int> path;
	path.push_back(0);
	score[0] = c[p++];
	while (path.size()) {
		auto pos = path.back();
		path.pop_back();
		for (auto v : G[pos]) {
			if (score[v] == 0) {
				path.push_back(v);
				M += (ll)(score[v] = c[p++]);
				//printf("p:%d\n", p);
			}
		}
	}
	printf("%lld\n", M);
	for(auto v : score) {
		printf("%d ", v);
	}
	puts("");
	return 0;
}
