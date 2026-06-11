#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;
int dp[MAXN][3];
int cost[MAXN][3];
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	dp[0][0] = cost[0][0], dp[0][1] = cost[0][1], dp[0][2] = cost[0][2];
	for (int i = 1; i < N; ++i) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}
	cout << max(dp[N-1][0],max(dp[N-1][1],dp[N-1][2])) << '\n';
	return 0;
}