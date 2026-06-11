#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;
int h[MAXN];
int dp[MAXN]; 
int N,K;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) cin >> h[i];
	fill(dp, dp + MAXN, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i+1; j < N && j-i <= K; ++j) {
			dp[j] = min(dp[j], dp[i] + abs(h[j] - h[i]));
		}
	}
	cout << dp[N - 1] << '\n';
	return 0;
}