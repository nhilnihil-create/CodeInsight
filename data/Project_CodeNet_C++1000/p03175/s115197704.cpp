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
const int MAXN = 100000;
const int LOGN = 19;
const int MOD = 1e9 + 7;
const int EPS = 1e-9;
const int MULT = 2e5;
const int MCNST = MOD * MOD * 8;

int dp[MAXN][2];
vector<vector<int>> g;

void dfs(int v, int p) {
	int a0 = 1, a1 = 1;
	for (int u: g[v]) {
		if (u != p) {
			dfs(u, v);
			a0 = (dp[u][0] + dp[u][1]) * a0 % MOD;
			a1 = a1 * dp[u][0] % MOD;
		}
	}

	dp[v][0] = a0;
	dp[v][1] = a1;
}

int32_t main() {
	FAST;
	
	int n;
	cin >> n;
	g.resize(n);

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(0, -1);

	cout << (dp[0][0] + dp[0][1]) % MOD;
}