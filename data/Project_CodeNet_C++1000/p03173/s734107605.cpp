// CODE © by 𝕌𝕥𝕜𝕒𝕣𝕤𝕙 𝔾𝕒𝕣𝕘
// Copying or sharing of this code without permission of the Author is strictly prohibited!!!
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Speed ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define endl "\n"
int dp[401][401];
int prf[401];
int f(int si, int ei) {
	// cout << si << " " << ei << endl;
	if (dp[si][ei] != -1)return dp[si][ei];
	if (si == ei)return 0;
	int &ans = dp[si][ei];
	ans = LLONG_MAX;
	for (int i = si; i < ei; i++) {
		ans = min(ans, f(si, i) + f(i + 1, ei) + prf[ei] - prf[si - 1]);
	}
	return ans;
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int a = 0, b = 0, c = 0, d = 0, i = 0, j = 0, k = 0, t = 0, n = 0, q = 0;
	cin >> n;
	for (int i = 0; i < 401; i++)
		for (int j = 0; j < 401; j++)dp[i][j] = -1;
	int arr[n + 1];
	memset(prf, 0, sizeof(prf));
	for (i = 1; i <= n; i++) {cin >> arr[i]; prf[i] += prf[i - 1] + arr[i];}
	cout << f(1, n);
}