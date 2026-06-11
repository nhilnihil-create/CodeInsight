// In The Name Of God
#include <bits/stdc++.h>

#define sqr(A) ((A) * (A))
#define X first
#define Y second
#define MP make_pair
#define bsz  __builtin_popcount
#define all(A) A.begin(), A.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int PR = 727;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;

const int N = 1e5 + 20;
ll a[N], n, p[N], fac[N], ans;

ll powmod(ll x, ll y, ll MODD = MOD) {
    if (y == 0) return 1LL;
    ll tmp = powmod(x, y / 2, MODD);
    tmp = sqr(tmp) % MODD;
    return (tmp * (y % 2 ? (x % MODD) : 1LL)) % MODD;
}

ll divmod(ll x, ll y, ll MODD = MOD) {
	return ((x % MODD) * powmod(y, MODD - 2, MODD)) % MODD;
}

ll C(ll r, ll n, ll MODD = MOD) {
    return divmod(fac[n], (fac[r] * fac[n - r]) % MODD, MODD);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	fac[0] = 1;
	for (ll i = 1; i < N; i++)
		fac[i] = (i * fac[i - 1]) % MOD;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= n; i++)
		p[i] = (p[i - 1] + ((C(i, n) * fac[i - 1]) % MOD) * fac[n - i]) % MOD;
	for (int i = 1; i <= n; i++)
		ans = (ans + a[i] * (p[n - i + 1] + p[i] - p[1])) % MOD;
	cout << ans << endl;
}

































