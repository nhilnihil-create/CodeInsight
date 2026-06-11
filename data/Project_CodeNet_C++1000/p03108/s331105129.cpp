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
struct UnionFind {
	vector<int> par, s;
	UnionFind(int N) : par(N), s(N, 1) { rep(i, 0, N)par[i] = i; }
	int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }
	void unite(int x, int y) { x = root(x), y = root(y); if (x == y)return; if (s[x] < s[y])swap(x, y); s[x] += s[y]; par[y] = x; }
	bool same(int x, int y) { return root(x) == root(y); }
	int size(int x) { return s[root(x)]; }
	map<int, int> cnt() { map<int, int> cnt; rep2(v, par)cnt[root(v)]++; return cnt; }
};
int main()
{
	ll n, m;
	cin >> n >> m;
	vector<pair<int, int>> br(m);
	rep(i, 0, m)cin >> br[i].first >> br[i].second, br[i].first--, br[i].second--;
	UnionFind uf(n);
	reverse(all(br));
	vector<ll> A;
	ll e_cnt = n * (n - 1) / 2;
	for (const auto& p : br)
	{
		A.push_back(e_cnt);
		if (!uf.same(p.first, p.second))
		{
			e_cnt -= uf.size(p.first) * uf.size(p.second);
			uf.unite(p.first, p.second);
		}
	}
	reverse(all(A));
	rep2(v, A)printf("%lld\n", v);
	return 0;
}