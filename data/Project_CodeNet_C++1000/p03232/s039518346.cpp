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
typedef vector <ll> vll;

const int N = 1e5 + 123, MOD = 1e9 + 7;
int n, a[N], fact[N], f[N];

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

void add(int & x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

void sub(int & x, int y) {
	x -= y;
	if (x < 0) {
		x += MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = (ll)fact[i - 1] * i % MOD;
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		f[i] = (ll)fact[n] * binpow(i + 1, MOD - 2) % MOD;
		add(r, f[i]);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int cont = (ll)(l + r) * a[i] % MOD;
		add(res, cont);
		if (i < n) {
			sub(r, f[n - i]);
			add(l, f[i]);
		}
	}
	cout << res;
}
