#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[100005];

int main() {
	int n; cin >> n;
	for (int i = 0; i < 100005; i++)dp[i] = 0;

	int x = 1, y = 6, z = 9;
	for (int i = 1; i <= n; i++) {
		if (i >= y * 6)y *= 6;
		if (i >= z * 9)z *= 9;
		if (i < 6)dp[i] = i;
		else if (i < 9) dp[i] = min(dp[i - x] + 1, dp[i - y] + 1);
		else  dp[i] = min({ dp[i - x] + 1,dp[i - y] + 1,dp[i - z] + 1 });
	}
	cout << dp[n] << endl;

	return 0;
}