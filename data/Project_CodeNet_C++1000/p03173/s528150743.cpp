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
#define inf (1ll)<<60

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


