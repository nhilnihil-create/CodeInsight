#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;

int mod = 1e9 + 7;
int arr[100];
int dp[100][100005];


// Hard to do this recursively so iterative dp with prefix sum is preferred
// dp[x][y] - x is childrens, y is candies, val at dp[x][y] is no of ways
// dp[first][0] - ways to distribute 0 candies is 1
// dp[x][y] = dp[x - 1][y] if we gave 0 candies to current child otherwise
//			  dp[x - 1][y - 1] if we gave 1 candy to current child
// dp[x][y] = prefix_sum[y] - prefix_sum[y - arr[x] - 1]
// dp[last][k] is our number of ways

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i <= arr[0]; i++)
		dp[0][i] = 1;

	for (int i = 1; i < n; i++) {
		// prefix sum
		vector<int> prefix(k + 1);
		prefix[0] = dp[i - 1][0];
		for (int j = 1; j <= k; j++)
			prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % mod;
		for (int j = 0; j <= k; j++) {
			if (j > arr[i])
				dp[i][j] = (prefix[j] + mod - prefix[j - arr[i] - 1]) % mod;
			else
				dp[i][j] = prefix[j];
		}
	}
	cout << dp[n - 1][k];
}