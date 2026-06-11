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

int dp[3000][3000];

int main() {
	FAST;

	int n;
	cin >> n;
	string s;
	cin >> s;
	dp[0][0] = 1;

	vector<ll> a(n + 1);
	for (int i = 1; i < n; i++) {
		a[0] = 0;
		for (int j = 0; j <= i; j++) {
			a[j + 1] = a[j] + dp[i - 1][j];
		}
		if (s[i - 1] == '<')
			for (int j = 1; j <= i; j++) {
				add_self(dp[i][j], a[j] % MOD);
			}
		else {
			for (int j = 0; j < i; j++) {
				add_self(dp[i][j], (a[i + 1] - a[j]) % MOD);
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) add_self(ans, dp[n - 1][i]);
	cout << ans;
}