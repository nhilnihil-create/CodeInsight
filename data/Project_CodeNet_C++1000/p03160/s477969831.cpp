#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 1e9 + 7;
int h[MAXN];
int dp[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < N; ++i) cin >> h[i];
	fill(dp, dp + MAXN, INF);
	dp[0] = 0;
	for (int i = 0; i < N - 1; ++i) {
		dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
		if(i < N-2	) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
	}
	cout << dp[N - 1] << '\n';
	return 0;
}