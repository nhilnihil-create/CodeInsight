#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
typedef long long int ll;

double arr[3000];
// double dp[3000][3000];
int n;
// double find(int i, int h) {
// 	if (i >= n) {
// 		if (h >= (n + 1) / 2)
// 			return 1;
// 		return 0;
// 	}

// 	if (dp[i][h] > -1)
// 		return dp[i][h];

// 	return dp[i][h] = arr[i] * find(i + 1, h + 1) + (1 - arr[i]) * find(i + 1, h);
// }


int main() {

	fastio;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		// cout << arr[i] << endl;
	}

	// memset(dp, -1, sizeof dp);
	// cout << fixed << setprecision(10) << find(0, 0);
	double dp[n + 1][n + 1];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == 0) {
				dp[i][j] = (1.0 - arr[i - 1]) * dp[i - 1][j];
			} else {
				dp[i][j] = arr[i - 1] * dp[i - 1][j - 1] + (1.0 - arr[i - 1]) * dp[i - 1][j];
			}
		}
	}
	double res = 0;
	for (int i = (n + 1) / 2; i <= n ; i++)
		res += dp[n][i];

	cout << fixed << setprecision(10) << res;
	return 0;
}


