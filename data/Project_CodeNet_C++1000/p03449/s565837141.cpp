#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> data(2 + 1, vector<int>(N+1,0));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> data[i][j];
		}
	}
	vector<vector<int>> dp(2 + 1, vector<int>(N + 1, 0));
	dp[0][0] = data[0][0];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + data[i + 1][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + data[i][j + 1]);
		}
	}
	cout << dp[1][N - 1] << endl;
	return 0;
}