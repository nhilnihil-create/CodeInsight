#include <iostream>
using namespace std;

const int mxN = 3e3 + 5;
double dp[mxN][mxN], a[mxN];

int main() {
	int n;
	scanf("%d", &n);
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		scanf("%lf", &a[i]);
		double t = 1 - a[i];
		dp[i][0] = dp[i - 1][0] * t;
		for(int j = 1; j <= i; ++j) {
			dp[i][j] = (double)dp[i - 1][j] * t;
			dp[i][j] += (double)dp[i - 1][j - 1] * a[i];
		}
	}
	double answer = 0;
	for(int i = (n + 1) / 2; i <= n; ++i)
		answer += dp[n][i];
	printf("%0.10f", answer);
}
