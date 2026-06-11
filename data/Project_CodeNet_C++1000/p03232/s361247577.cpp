#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

ll mod = 1000000007;
ll modsize = 100010;

ll modinv(ll a) {
	ll b = mod, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= mod;
	if (u < 0) u += mod;
	return u;
}

ll modpow(ll a, ll b) {
	ll ans = 1;
	a %= mod;
	while (b) {
		if (b & 1) ans = ans * a%mod;
		a = a * a%mod;
		b >>= 1;
	}
	return ans;
}

vector<ll> fac(modsize + 5);
vector<ll> inv(modsize + 5);
vector<ll> facinv(modsize + 5);

void modcalc() {
	fac[0] = fac[1] = 1; inv[1] = 1;
	facinv[0] = facinv[1] = 1;
	for (int i = 2; i < modsize; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod%i] * (mod / i) % mod;
		facinv[i] = facinv[i - 1] * inv[i] % mod;
	}
}

ll modcomb(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll modperm(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[n - k] % mod;
}

ll modhom(ll n, ll k) {
	if (n < 0 || k < 0) return 0;
	if (n == 0 && k == 0) return 1;
	return modcomb(n + k - 1, k);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	modcalc();

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int bs = 0;
	for (int i = 1; i <= n; i++) {
		bs += inv[i];
		if (bs > mod) bs -= mod;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		a[i] *= bs; a[i] %= mod;
		ans += a[i];
		if (ans > mod) ans -= mod;
		bs += inv[i + 2];
		bs -= inv[n - i];
		if (bs < 0) bs += mod;
		if (bs > mod) bs -= mod;
	}
	for (int i = 1; i <= n; i++) {
		ans *= i; ans %= mod;
	}
	cout << ans << endl;
}