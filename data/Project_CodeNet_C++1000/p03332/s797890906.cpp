#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

ll mod(ll a) {
	if (a > 0) return a % MOD;
	if (a % MOD == 0) return 0;
	ll x = -a / MOD + 1;
	a += x * MOD;
	return a % MOD;
}
ll powm(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		ll d = powm(a, b / 2, c);
		return (d * d) % c;
	} else
		return (a * powm(a, b - 1, c)) % c;
}
template <typename T> void dump(T x) { cout << x << endl; }
void dumpf(double x, ll t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
// ll dx[4] = {1, 0, -1, 0};
// ll dy[4] = {0, 1, 0, -1};
// ll pas[5001][5002];

ll fact[364364] = {}, facti[364364] = {};

const ll MOD2 = 998244353;
ll n;
ll ok(ll a, ll b) { return (a % b == 0 && a / b >= 0 && a / b <= n); }

int main() {
	IOS();
	ll a, b, k;
	cin >> n >> a >> b >> k;
	fact[0] = facti[0] = 1;
	for (ll i = 1; i <= n; ++i) {
		fact[i]  = (fact[i - 1] * i) % MOD2;
		facti[i] = powm(fact[i], MOD2 - 2, MOD2);
	}
	ll ans = 0;
	for (ll i = 0; i <= n; ++i) {
		if (ok(k - i * a, b)) {
			ll j   = (k - i * a) / b;
			ll tmp = (((fact[n] * facti[i]) % MOD2) * facti[n - i]) % MOD2;
			tmp *= (((fact[n] * facti[j]) % MOD2) * facti[n - j]) % MOD2;
			tmp %= MOD2;
			ans += tmp;
			ans %= MOD2;
		}
	}
	dump(ans);
	return 0;
}