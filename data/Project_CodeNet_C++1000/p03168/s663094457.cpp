#include <bits/stdc++.h>
using namespace std;


const int S = 3e3 + 3;
double dp[S][S];

int main() {
int n;
	scanf("%d", &n);
	vector<double> H(n + 1), T(n + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> H[i];
		T[i] = (1 - H[i]);
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = (double)dp[i - 1][0] * T[i];
		for(int j = 1; j <= n; ++j) {
			dp[i][j] = (double)H[i] * dp[i - 1][j - 1] + (double)T[i] * dp[i - 1][j];
		}
	}
	double ans = 0;
	for(int j = n; j > n / 2; --j) {
		ans += dp[n][j];
	}
  	printf("%0.10f", ans);
}
