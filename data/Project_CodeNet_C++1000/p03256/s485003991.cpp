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
#define H pair<int, int>
#define P pair<int, pair<int, int>>
#define Q(i,j,k) mkp(i,mkp(j,k))
#define rep(i,n) for(int (i) = 0 ; (i) < (n) ; (i)++)
#define mkp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define crdcomp(b) sort(all((b)));(b).erase(unique(all((b))),(b).end())
const int mod = 1e9 + 7;
const int Mod = 998244353;
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
const int fn_ = 2000000;
ll fact_[fn_], comp_[fn_];
ll comb(ll x, ll y, ll Mod = mod) {
	if (!fact_[0]) {
		fact_[0] = 1; comp_[0] = 1;
		for (int i = 1; i < fn_; i++) {
			fact_[i] = fact_[i - 1] * i % Mod;
			comp_[i] = mod_pow(fact_[i], Mod - 2, Mod);
		}
	}
	if (x < y) return 0;
	return fact_[x] * comp_[x - y] % Mod * comp_[y] % Mod;
}
//---------------------------------------------------
int n, m;
string s;
H a[300000];
vector<int>e[300000];
bool b[300000];
signed main() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
		if (s[u - 1] == 'A') a[v].fs++;
		else a[v].sc++;
		if (s[v - 1] == 'A') a[u].fs++;
		else a[u].sc++;
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (a[i].fs == 0 || a[i].sc == 0) {
			q.push(i);
		}
	}
	int ans = n;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		if (b[t]) continue;
		b[t] = 1; n--;
		for (auto g : e[t]) {
			if (s[t - 1] == 'A') a[g].fs--;
			else a[g].sc--;
			if (a[g].fs == 0 || a[g].sc == 0) q.push(g);
		}
	}
	if (n == 0) cout << "No\n";
	else cout << "Yes\n";
}