#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
	
#define int long long
#define double long double 
#define PI 3.141592653589793
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
// Use for file I/O;
#define FIN string _fname = "homework"; \
			string _is = _fname + ".in", _os = _fname + ".out"; \
			freopen(_is.c_str(), "r", stdin); \
			freopen(_os.c_str(), "w", stdout);

using namespace std;
	
int gcd(int a, int b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

const int INF = 4e18 + 10;
const int INF2 = 2e18 + 10;
const int INF3 = 2e10;
const int MAXN = 200000;
const int LOGN = 19;
const int MOD = 1e9 + 7;
const int EPS = 1e-9;
const int MULT = 2e5;
const int MCNST = MOD * MOD * 8;

int h[MAXN], a[MAXN], dp[MAXN + 1], t[MAXN*4];

int query(int v, int tl, int tr, int l, int r) {
	if (l >= r) return 0;
	else if (tl == l && tr == r) return t[v];
	else {
		int tm = (tl + tr) / 2;
		int r1 = query(2*v + 1, tl, tm, l, min(r, tm));
		int r2 = query(2*v + 2, tm, tr, max(l, tm), r);
		return max(r1, r2);
	}
}

void update(int v, int tl, int tr, int i, int x) {
	if (tl == tr - 1) t[v] = x;
	else {
		int tm = (tl + tr) / 2;
		if (i < tm) {
			update(2*v + 1, tl, tm, i, x);
		} else {
			update(2*v + 2, tm, tr, i, x);
		}
		t[v] = max(t[2*v + 1], t[2*v + 2]);
	}
}

int32_t main() {
	FAST;
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
		h[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
	}

	for (int i = 0; i <= 4*n; i++) {
		t[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		dp[i + 1] = query(0, 0, n, 0, h[i] + 1) + a[i];
		update(0, 0, n, h[i], dp[i + 1]);
	}

	cout << *max_element(dp, dp + n + 1);
}