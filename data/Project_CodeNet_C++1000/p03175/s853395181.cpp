#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

/*
int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	return 0;
}

*/

//problem - M

/* int main() {

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int n, k;
cin >> n >> k;
vector<int> a(n + 1, 0);
for (int i = 1; i <= n; i++)
	cin >> a[i];
vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

for (int i = 0; i <= k; i++)
	dp[1][i] = (i <= a[1]) ? 1 : 0;

for (int i = 2; i <= n; i++) {
	for (int j = 0; j <= k; j++) {
		if (j == 0)
			dp[i][j] = dp[i - 1][j];
		else
			dp[i][j] = (mod + dp[i][j - 1] + dp[i - 1][j] - ((j - 1 - a[i]) >= 0 ? dp[i - 1][j - 1 - a[i]] : 0) ) % mod;
	}
}


cout << dp[n][k] << endl;
return 0;
} */

// problem - N

//long long dp[402][402];
//long long  sum[402];
/*#define inf (1ll)<<60

long long solve(vector<long long> &a, vector<vector<long long>> &dp, vector<long long> &sum, int i, int j) {

	if (i == j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	//long long _min = 400ll * 1000000007;
	long long _min = inf;
	for (int k = i; k < j; k++) {
		_min = min(_min, sum[j] - sum[i - 1] + solve(a, dp, sum, i, k) + solve(a, dp, sum, k + 1, j));
	}
	return dp[i][j] = _min;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<long long> a(n + 1, 0);
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
	vector<long long> sum(n + 1, 0);
	//memset(dp, sizeof dp, -1);
	//memset(sum, sizeof sum, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	cout << solve(a, dp, sum, 1, n) << endl;
	return 0;
}

*/

/*


//Problem O

int n;

long long solve(vector<vector<int>> &compat, vector<vector<int>> &dp, int m, int mask) {
	if (m == (n + 1)) {
		if (mask == 0)
			return 1;
		return 0;
	}
	if (dp[m][mask] != -1)
		return dp[m][mask];

	long long ans = 0;

	for (int w = 0; w < n; w++) {
		if ( compat[m][w + 1] && ((1 << w)&mask) )
			ans = (ans + solve(compat, dp, m + 1, (1 << w)^mask) ) % mod;
	}
	return dp[m][mask] = ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	vector<vector<int>> compat(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> dp(22, vector<int>((1 << 22), -1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> compat[i][j];
	cout << solve(compat, dp, 1, (1 << n) - 1) << endl;
	return 0;
}

*/

// Problem P

long long solve(vector<vector<int>> &g, vector<vector<int>> &dp, int src, int constraint, int pr) {

	if (dp[src][constraint] != -1)
		return dp[src][constraint];

	long long ans = 0;
	long long w1 = 1;
	//if there is constraint, child can only take white
	for (int i = 0; i < g[src].size(); i++) {
		if (g[src][i] != pr)
			w1 = (w1 * solve(g, dp, g[src][i], 0, src) ) % mod;
	}
	ans = (ans + w1) % mod;

	//if there is no constraint child can take any color

	long long w2 = 1;
	if (constraint == 0) {
		for (int i = 0; i < g[src].size(); i++) {
			if (g[src][i] != pr)
				w2 = (w2 * solve(g, dp, g[src][i], 1, src) ) % mod;
		}
		ans = (ans + w2) % mod;
	}
	return dp[src][constraint] = ans;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	vector<vector<int>> dp(n + 2, vector<int>(2, -1));
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << solve(g, dp, 1, 0, -1) << endl;

	return 0;
}