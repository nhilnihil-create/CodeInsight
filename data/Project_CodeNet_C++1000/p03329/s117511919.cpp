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
	vector<int> dp(N + 1, 1000000);
	dp[0] = 0;
	int n;
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; ; j++) {
			if (i - pow(6, j) >= 0) {
				chmin(dp[i], dp[i - pow(6, j)] + 1);
			}
			else break;
			if (i - pow(9, j) >= 0) {
				chmin(dp[i], dp[i - pow(9, j)] + 1);
			}
		}
	}
	cout << dp[N] << endl;
}