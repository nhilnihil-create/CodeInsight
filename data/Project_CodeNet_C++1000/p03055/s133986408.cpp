#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<unordered_map>
#include<climits>
#include<fstream>
#include<time.h>
#include<cassert>

using namespace std;
#define ll long long
#define ld long double
#define int long long
#define all(a) (a).begin(),(a).end()
#define EPS (1e-13)
#define fs first
#define sc second
#define xx first
#define yy second.first
#define zz second.second
#define P pair<int, int>
#define Q pair<int, pair<int, int>>
#define rep(i,n) for(int (i) = 0 ; (i) < (n) ; (i)++)
#define mkp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define crdcomp(b) sort(all((b)));(b).erase(unique(all((b))),(b).end())
const int Mod = 1e9 + 7;
const int mod = 998244353;
const ll Inf = 3 * 1e18;
const int inf = 15 * 1e8;
ll read() {
	ll u, k = scanf("%lld", &u);
	return u;
}
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j % i, i);
}
ll mod_pow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return res;
}
ll bcount(ll x) {
	int sum = 0;
	for (int i = 0; i < 20; i++)
		if ((1ll << i) & x) sum++;
	return sum;
}
/*const int fn_ = 2000000;
ll fact_[fn_], comp_[fn_];
ll comb(ll x, ll y, ll mod = Mod) {
	if (!fact_[0]) {
		fact_[0] = 1; comp_[0] = 1;
		for (int i = 1; i < fn_; i++) {
			fact_[i] = fact_[i - 1] * i % mod;
			comp_[i] = mod_pow(fact_[i], mod - 2, mod);
		}
	}
	if (x < y) return 0;
	return fact_[x] * comp_[x - y] % mod * comp_[y] % mod;
}*/
//---------------------------------------------------
int n;
int a[500000];
vector<int>e[500000];
int dp[500000];
signed main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	fill(a + 2, a + n + 1, inf);
	queue<int>q;
	q.push(1);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (auto g : e[t]) {
			if (a[g] > a[t] + 1) {
				a[g] = a[t] + 1;
				q.push(g);
			}
		}
	}
	int mx = 1;
	for (int i = 2; i <= n; i++) {
		if (a[mx] < a[i]) mx = i;
	}
	int r = 1;
	q.push(mx);
	fill(a + 1, a + n + 1, inf);
	a[mx] = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (auto g : e[t]) {
			if (a[g] > a[t] + 1) {
				a[g] = a[t] + 1;
				q.push(g);
			}
		}
	}
	mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, a[i]);
	}
	//mx=直径
	dp[1] = 1;
	dp[2] = 0;//このタイミングで始まった人が勝つか
	for (int i = 3; i <= mx + 1; i++) {
		if (!dp[i - 2] || !dp[i - 1]) dp[i] = 1;
		else dp[i] = 0;
	}
	if (dp[mx + 1]) cout << "First\n";
	else cout << "Second\n";
}