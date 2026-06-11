#include <bits/stdc++.h>
using namespace std;
int n;
int t[105], v[105];
vector <int> lim;
double dp[40005][205];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &t[i]);
	for (int i = 0; i < n; ++ i) scanf("%d", &v[i]);
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < 2 * t[i]; ++ j) {
			lim.push_back(2 * v[i]);
		}
	}
	for (int i = 0; i <= lim.size(); ++ i) {
		for (int j = 0; j <= 200; ++ j) {
			dp[i][j] = -1e18;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < lim.size(); ++ i) {
		for (int j = 0; j <= lim[i]; ++ j) {
			if (j && j - 1 <= lim[i]) dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + j - 0.5);
			if (j <= lim[i]) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + j);
			if (j + 1 <= lim[i]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + j + 0.5);
		}
	}
	printf("%.9f\n", dp[lim.size()][0] / 4.0);
	return 0;
}