//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18 + 69;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll fact[300100], inv[300100];
ll bp(ll a, ll p) {
	ll r = 1;
	while (p) {
		if (p & 1)
			r = (r * a) % mod;
		p >>= 1;
		a = (a * a) % mod;
	}
	return r;
}
ll setup() {
	fact[0] = 1;
	for (int i = 1; i < 300100; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	inv[300100 - 1] = bp(fact[300100 - 1], mod - 2);
	for (int i = 300100 - 1; i--;)
		inv[i] = (inv[i + 1] * (i + 1)) % mod;
}
ll nck(ll n, ll k) {
	if(k>n) return 0;
	ll r = (fact[n] * inv[n - k]) % mod;
	return (r * inv[k]) % mod;
}
ll n, a, b, k;
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	setup();
	cin >> n >> a >> b >> k;
	ll ans = 0;
	for(ll i = 0; i*a <= k; i++) {
		if((k-i*a)%b) continue;
		ll j = (k-i*a)/b;
		ans = (ans + nck(n, i)*nck(n, j))%mod;
	}
	cout << ans;
}
