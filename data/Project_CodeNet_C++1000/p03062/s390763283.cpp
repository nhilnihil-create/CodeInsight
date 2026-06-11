
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e18;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

const ll mod = 1000000007;

ll mpow(ll x, ll n) {
	ll ans = 1; x %= mod;
	while (n != 0) {
		if (n & 1) ans = ans * x % mod;
		x = x * x % mod;
		n = n >> 1;
	}
	return ans;
}

ll inv_mod(ll a) { return mpow(a, mod - 2); }

class Factorial {
private:
	vector<ll> fac;
	vector<ll> ifac;
public:

	Factorial(ll N) {
		fac.push_back(1);
		for (int i = 0; i < N; i++) fac.push_back(fac[i] * (i + 1) % mod);
		ifac.resize(N + 1);
		ifac[N] = inv_mod(fac[N]);
		for (int i = 0; i < N; i++) ifac[N - 1 - i] = (ifac[N - i] * (N - i)) % mod;
	}

	ll fact(ll a) { return fac[a]; }
	ll ifact(ll a) { return ifac[a]; }

	ll cmb(ll a, ll b) {
		if (a == 0 && b == 0) return 1;
		if (a < b || a < 0 || b < 0) return 0;
		ll tmp = ifact(a - b) * ifact(b) % mod;
		return tmp * fac[a] % mod;
	}
	ll per(ll a, ll b) {
		if (a == 0 && b == 0) return 1;
		if (a < b || a < 0 || b < 0) return 0;
		return fac[a] * ifac[a - b] % mod;
	}
};


int main() {
	ll n;
	cin >> n;
	vector<ll> as(n);
	rep(i, n) cin >> as[i];
	ll minus = 0;
	vector<ll> ab(n);
	rep(i, n) {
		ab[i] = abs(as[i]);
		if (as[i] < 0) {
			minus++;
		}
	}
	sort(ab.begin(), ab.end());
	ll s = ab[0];
	if (minus % 2 == 1) {
		s = -ab[0];
	}
	for (int i = 1; i < n; i++) {
		s += ab[i];
	}
	cout << s << endl;
	return 0;
}
