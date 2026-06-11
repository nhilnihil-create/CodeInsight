#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
	int N;
	cin >> N;
	vector<vector<int>> dp(N + 1, vector<int>(3));
	int a, b, c;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		dp[i][0] = max(dp[i - 1][1] + a, dp[i - 1][2] + a);
		dp[i][1] = max(dp[i - 1][0] + b, dp[i - 1][2] + b);
		dp[i][2] = max(dp[i - 1][0] + c, dp[i - 1][1] + c);
	}
	cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;
}