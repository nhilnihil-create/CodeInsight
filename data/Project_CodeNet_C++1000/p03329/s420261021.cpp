#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>dp(N + 1, 1e9);
	dp[0] = 0;
	int a = 1;
	int b = 1;
	int c = 1;
	for (int i = 1; i < 1 + N; ++i) {
		while (b * 6 <= i) {
			b *= 6;
		}
		while (c * 9 <= i) {
			c *= 9;
		}
		dp[i] = min(min(dp[i - a] + 1, dp[i - b] + 1), dp[i - c] + 1);
	}
	cout << dp[N] << endl;
}