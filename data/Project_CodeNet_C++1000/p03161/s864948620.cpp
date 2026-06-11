#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> h(N);
	for (int i = 0; i < N; i++) cin >> h[i];
	vector<int> dp(N, 1000000000);
	dp[0] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j <= K; j++) {
			if (i + j >= N) break;
			dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
		}
	}
	cout << dp[N - 1] << endl;
}