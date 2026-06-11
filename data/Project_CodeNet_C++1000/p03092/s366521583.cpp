#include <iostream>
#include <algorithm>
using namespace std;

long long N, A, B, C[5009];
long long dp[5009][5009];

int main() {
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++) cin >> C[i];

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) dp[i][j] = (1LL << 60);
	}
	
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		long long r = (1LL << 60);
		for (int j = 0; j <= C[i] - 1; j++) r = min(r, dp[i - 1][j]);
		dp[i][C[i]] = r;
		for (int j = 0; j <= C[i] - 1; j++) { dp[i][j] = dp[i - 1][j] + A; }
		for (int j = C[i] + 1; j <= N; j++) { dp[i][j] = dp[i - 1][j] + B; }
	}

	long long ret = (1LL << 60);
	for (int i = 0; i <= N; i++) ret = min(ret, dp[N][i]);
	cout << ret << endl;
	return 0;
}