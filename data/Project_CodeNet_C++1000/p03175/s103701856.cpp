#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100005
#define mod 1000000007

int dp[N][2], n, u, v;  // 0: white 1 : black
vector<vector<int> > g(100005, vector<int> (0));

int solve(int u, int tight, int par) {
	if (dp[u][tight] != -1) {
		return dp[u][tight];
	}
	dp[u][tight] = 0;
	ll prod1 = 1, prod2 = 1;

	for (auto it : g[u]) {
		if (it != par) {
			prod1 *= solve(it, 0, u);
			prod1 %= mod;
			if (!tight) {
				prod2 *= solve(it, 1, u);
				prod2 %= mod;
			}
		}
	}

	dp[u][tight] += prod1;
	//dp[u][tight] %= mod;
	if (!tight) {
		dp[u][tight] += prod2;
	}

	return dp[u][tight] % mod;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (n == 1) {
		cout << 2 << "\n";
		return 0;
	}

	memset(dp, -1, sizeof dp);
	cout << solve(1, 0, -1);
}