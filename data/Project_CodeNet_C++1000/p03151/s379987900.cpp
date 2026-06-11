#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

const ll mod = 1e9 + 7;

const ll INF = 1e15;

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
	vector<ll> as(n), bs(n);
	ll asum = 0, bsum = 0;
	rep(i, n) {
		cin >> as[i];
		asum += as[i];
	}
	rep(i, n) {
		cin >> bs[i];
		bsum += bs[i];
	}
	if (bsum > asum) {
		cout << -1 << endl;
		return 0;
	}
	vector<ll> ps, ms;
	rep(i, n) {
		auto diff = bs[i] - as[i];
		if (diff > 0) {
			ms.emplace_back(diff);
		}
		else if (diff < 0) {
			ps.emplace_back(-diff);
		}
	}
	int i = 0, j = 0;
	ll take = 0;
	ll all = 0;
	sort(ps.begin(), ps.end(), std::greater<ll>());
	while (j < ms.size()) {
		if (take > 0) {
			take -= ms[j];
			j++;
			all++;
		}
		while (i < ps.size() && take <= 0)
		{
			take += ps[i];
			i++;
			all++;
		}
	}
	cout << all << endl;
	return 0;
}
