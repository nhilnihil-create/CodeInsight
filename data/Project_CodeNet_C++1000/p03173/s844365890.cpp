#include "bits/stdc++.h"
using namespace std;
#define Fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long

int n;
vector<int> a;
vector<vector<int>> dp;
int sm(int i, int j) {
	int ans = 0;
	for (int k = i; k <= j; k++)
		ans += a[k];
	return ans;
}

int solve(int i, int j) {
	if (i == j)
		return a[i];
	if (i > j)
		return 0;
	if (~dp[i][j])
		return dp[i][j];
	int ans = 4e18;
	for (int k = i; k < j; k++) {
		int l = solve(i, k);

		int r = solve(k + 1, j);
		ans = min(ans, l + r + sm(i, k) + sm(k + 1, j));
	}

	return dp[i][j] = ans;
}

int32_t main() {
	Fast_IO
	cin >> n;
	a = vector<int>(n);
	dp = vector<vector<int>>(n, vector<int>(n, -1));
	for (auto &i : a)
		cin >> i;
	int t = solve(0, n - 1);
	t -= accumulate(a.begin(), a.end(), 0LL);;
	cout << t;
}