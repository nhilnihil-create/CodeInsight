#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 22
#define mod 1000000007

ll dp[N][2097155];
int c[N][N], n;

ll solve(int i, ll s) {
	if (s == 0) {
		return 1;
	}

	if (i == n) {
		return 0;
	}

	if (dp[i][s] != -1) {
		return dp[i][s];
	}

	ll tmp = s;
	dp[i][s] = 0;

	for (int j = 0; j < n; j++) {
		int bit = tmp & 1;
		if (bit && c[i][j] == 1) {
			dp[i][s] = (dp[i][s] + solve(i + 1, (s ^  (1 << j)))) % mod;
		}
		tmp = tmp >> 1;
	}

	return dp[i][s];
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}

	memset(dp, -1, sizeof dp);
	ll s = 0;
	for (int i = 0; i < n; i++) {
		s += 1 << i;
	}

	//cout << s;
	cout << solve(0, s);

}