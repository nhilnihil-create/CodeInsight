#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

long long dp[N], n, a, b, P[N], S[N][N];

int calc(int L, int R, int l, int r) {
	L = max(L, 1); l = max(l, 1);
	return S[R][r] - S[L - 1][r] - S[R][l - 1] + S[L - 1][l - 1];
}

int main() {
	cin >> n >> a >> b;
	for(int i = 1; i <= n; ++ i) cin >> P[i], S[P[i]][i] = 1;
	S[n + 1][n + 1] = 1;
	P[n + 1] = n + 1;
	for(int i = 1; i <= n + 1; ++ i) {
		for(int j = 1; j <= n + 1; ++ j)
		S[i][j] = S[i - 1][j] + S[i][j - 1] + S[i][j] - S[i - 1][j - 1];
	}
	for(int i = 0; i <= n + 1; ++ i) dp[i] = 1e18;
	dp[0] = 0;
	for(int i = 0; i <= n; ++ i) {
		for(int j = i + 1; j <= n + 1; ++ j) if(P[j] > P[i]) {
			// [P[i] + 1, P[j] - 1], [1, i - 1], [j + 1, n]
			int now = calc(P[i] + 1, P[j] - 1, i + 1, j - 1);
			if(now) continue;
			dp[j] = min(dp[j], dp[i] + calc(1, P[i], i + 1, j - 1) * b + calc(P[j], n, i + 1, j - 1) * a);
		}
	}
	cout << dp[n + 1] << endl;
}