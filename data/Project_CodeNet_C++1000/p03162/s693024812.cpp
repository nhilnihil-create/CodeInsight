#include <iostream>
#include <algorithm>
using namespace std;
int a[111111][10];
int dp[111111][11];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = max(dp[i-1][2], dp[i-1][3]) + a[i][1];
		dp[i][2] = max(dp[i-1][1], dp[i-1][3]) + a[i][2];
		dp[i][3] = max(dp[i-1][2], dp[i-1][1]) + a[i][3];
	}
	cout << max(dp[n][1], max(dp[n][2], dp[n][3]));
}