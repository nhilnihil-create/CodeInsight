#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;

const int N = 3e5 + 123, MOD = 998244353;
ll n, a, b, k;
int fact[N], rev[N];

int binpow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) {
			res = (ll)res * x % MOD;
		}
		x = (ll)x * x % MOD;
		y /= 2;
	}
	return res;
}

int c(int x, int y) {
	if (y > x) {
		return 0;
	}
	return ((ll)fact[x] * rev[y] % MOD) * rev[x - y] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> a >> b >> k;
	fact[0] = rev[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (ll)fact[i - 1] * i % MOD;
		rev[i] = (ll)rev[i - 1] * binpow(i, MOD - 2) % MOD;
	}
	int res = 0;
	for (int i = 0; i <= n; i++) {
		ll l = k - i * a;
		if (l < 0 || l % b) {
			continue;
		}
		l /= b;
		res += (ll)c(n, i) * c(n, l) % MOD;
		if (res >= MOD) {
			res -= MOD;
		}
	}
	cout << res;
}
