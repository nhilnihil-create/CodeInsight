/*
	author: Ibrahim-Elsayed (Codeforces Handle)
	date: 9/17/2020
*/
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int64_t INF = (int64_t)1e18;
const int mxN = 1e5+20;

int n;
int64_t arr[mxN+1][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	// dp[i][j] max happ points can get ending at day i with last used j;
	vector<vector<int64_t>> dp(n+1, vector<int64_t>(3));
	dp[0][0] = dp[0][1] = dp[0][2] = 0; // empty set of activities, max we can get here is 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			dp[i][j] = -INF;
			if(i == 1) {
				dp[i][j] = max({arr[i][0], arr[i][1], arr[i][2]});
			} else {
				if(j != 0) {
					dp[i][j] = max(dp[i][j], dp[i-1][0] + arr[i][0]);
				}
				if(j != 1) {
					dp[i][j] = max(dp[i][j], dp[i-1][1] + arr[i][1]);
				}
				if(j != 2) {
					dp[i][j] = max(dp[i][j], dp[i-1][2] + arr[i][2]);
				}
			}
		}
	}
	cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";

	return 0;
}
