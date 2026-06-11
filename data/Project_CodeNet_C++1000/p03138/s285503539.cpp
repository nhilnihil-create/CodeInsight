#include "bits/stdc++.h"
using namespace std;
long long dp[101][2];

int main() {
	long long N, K;
	cin >> N >> K;
	vector<long long>A(N);
	for (int n = 0; n < N; ++n) {
		cin >> A[n];
	}
	for (int n = 0; n < 101; ++n) {
		dp[n][0] = dp[n][1] = -1;
	}
	dp[0][0] = 0;
	for (int n = 0; n < 40; ++n) {
		long long mask = 1LL << (39 - n);
		long long count = 0;
		for (int i = 0; i < N; ++i) {
			if (A[i] & mask) {
				count++;
			}
		}
		if (dp[n][1] >= 0) {
			dp[n + 1][1] = max(dp[n + 1][1], dp[n][1] + mask * max(count, N - count));
		}
		if (dp[n][0] >= 0) {
			if (K&mask) {
				dp[n + 1][1] = max(dp[n + 1][1], dp[n][0] + mask * count);
				dp[n + 1][0] = max(dp[n + 1][0], dp[n][0] + mask * (N - count));
			}
			else {
				dp[n + 1][0] = max(dp[n + 1][0], dp[n][0] + mask * count);
			}
		}

	}
	cout << max(dp[40][0], dp[40][1]) << endl;
	return 0;
}
