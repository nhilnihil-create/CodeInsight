#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int K, dp[309][309][309]; string S;

int solve(int l, int r, int c) {
	if (c > K) return -(1 << 30);
	if (l > r) return 0;
	if (l == r) return 1;
	if (dp[l][r][c] >= 0) return dp[l][r][c];
	int ret = 0;
	ret = max(ret, solve(l + 1, r, c));
	ret = max(ret, solve(l, r - 1, c));
	if (S[l] == S[r]) ret = max(ret, solve(l + 1, r - 1, c) + 2);
	else ret = max(ret, solve(l + 1, r - 1, c + 1) + 2);
	dp[l][r][c] = ret;
	return ret;
}

int main() {
	cin >> S >> K;
	for (int i = 0; i < 309; i++) { for (int j = 0; j < 309; j++) { for (int k = 0; k < 309; k++) dp[i][j][k] = -1; } }
	cout << solve(0, S.size() - 1, 0) << endl;
	return 0;
}