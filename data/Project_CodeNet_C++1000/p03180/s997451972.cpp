#pragma GCC optimize ("Ofast")
#include "bits/stdc++.h"
	
#define PI 3.141592653589793
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
// Use for file I/O;
#define FIN string _fname = "paintbarn"; \
			string _is = _fname + ".in", _os = _fname + ".out"; \
			freopen(_is.c_str(), "r", stdin); \
			freopen(_os.c_str(), "w", stdout);

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e9 + 10;
const ll INF2 = 3e18 + 10;
const int MOD = 1e9 + 7;
const ld EPS = 1e-4;

const int LOGN = 19;
const int MAXN = 305;


inline void add_self(int &a, int b) {
	a = (a + b) % MOD;
}

ll dp[1 << 16];
ll t[1 << 16];
ll p[16][16];
int a[16];

int main() {
	FAST;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 0; i < (1 << n); i++) dp[i] = -INF2;

	for (int mask = 0; mask < (1 << n); mask++) {
		for (int i = 0; i < n; i++) {
			if ((mask >> i) & 1) {
				for (int j = i + 1; j < n; j++) {
					if ((mask >> j) & 1) {
						t[mask] += p[i][j];
					}
				}
			}
		}
	}

	dp[0] = 0;
	int pn = (1 << n) - 1;
	for (int mask = 0; mask < (1 << n); mask++) {
		int m = mask ^ pn;
		for (int s = m; s; s=(s - 1) & m) {
			dp[s|mask] = max(dp[s|mask], dp[mask] + t[s]);
		} 
	}
	cout << dp[(1 << n) - 1];

}