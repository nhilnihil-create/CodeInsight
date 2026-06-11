/*
─────────────────────
───────────████████──
──────────███▄███████
──────────███████████
──────────███████████
──────────██████─────
──────────█████████──
█───────███████──────
██────████████████───
███──████AJ████──█───
███████████████──────
███████████████──────
─█████████████───────
──███████████────────
────████████─────────
─────███──██─────────
─────██────█─────────
─────█─────█─────────
─────██────██────────
─────────────────────
*/

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

int N;
const int maxN = 401;
// ll dp[maxN][maxN];
ll a[maxN];

// ll getMax(int start, int end) {
// 	if (start == end) return 0;
// 	if (dp[start][end] != -1) return dp[start][end];

// 	ll result = LLONG_MAX;
// 	ll sum = 0;
// 	for (int i = start; i <= end; i++) {
// 		sum += a[i];
// 	}
// 	for (int i = start; i < end; i++) {
// 		ll r1 = getMax(start, i);
// 		ll r2 = getMax(i + 1, end);
// 		result = min(result, r1 + r2 + sum);
// 	}

// 	return dp[start][end] = result;
// }

ll bottomUp() {
	ll dp[N][N];
	for (int i = 0; i < N; i++) {
		dp[i][i] = 0;
	}

	for (int L = 2; L <= N; L++) {
		for (int start = 0; start <= N - L; start++) {
			int end = start + L - 1;
			dp[start][end] = LLONG_MAX;
			ll sum = 0;
			for (int i = start; i <= end; i++) {
				sum += a[i];
			}
			for (int k = start; k < end; k++) {
				dp[start][end] = min(dp[start][end], dp[start][k] + dp[k + 1][end] + sum);
			}
		}
	}
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < N; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return dp[0][N - 1];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	// memset(dp, -1, sizeof(dp));
	// ll res = getMax(0, N - 1);
	ll res = bottomUp();
	cout << res << endl;
	return 0;
}