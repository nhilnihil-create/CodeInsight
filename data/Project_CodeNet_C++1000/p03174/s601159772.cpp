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
const int MAXN = 303;
const int LOGN = 19;
const int MOD = 1e9 + 7;
const int EPS = 1e-9;
const int MULT = 2e5;
const int MCNST = MOD * MOD * 8;

int dp[22][(1 << 21)];
bool a[21][21];
vector<int> m[22];

int32_t main() {
	FAST;
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}	

	for (int mask = 0; mask < (1 << n); mask++) {
		m[__builtin_popcount(mask)].push_back(mask);
	}

	for (int i = 0; i <= n; i++) {
		for (int mask: m[i]) {
			dp[i][mask] = 0;
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int mask: m[i]) {
			for (int k = 0; k < n; k++) {
				if (!((mask >> k) & 1)) {
					if (a[i][k]) {
						int nm = mask | (1 << k);
						dp[i + 1][nm] += dp[i][mask];
						dp[i + 1][nm] %= MOD;
					}
				}
			}
		}
	}
	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j < (1 << n); j++) {
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	cout << dp[n][(1 << n) - 1];
}