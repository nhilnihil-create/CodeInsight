// CODE © by 𝕌𝕥𝕜𝕒𝕣𝕤𝕙 𝔾𝕒𝕣𝕘
// Copying or sharing of this code without permission of the Author is strictly prohibited!!!
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Speed ios::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define endl "\n"
int power(int x, int n, int mod) {int res = 1; x %= mod; while (n) {if (n & 1)res = (res * x) % mod; x = (x * x) % mod; n >>= 1;} return res;}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int a = 0, b = 0, c = 0, d = 0, i = 0, j = 0, k = 0, t = 0, n = 0, q = 0;
	cin >> n >> k;
	unordered_set<int> arr;
	int dp[k + 1] = { -1};
	memset(dp, -1, sizeof(dp));
	// for (auto i : dp)cout << i << " "; cout << endl;

	for (int i = 0; i < n; i++) {cin >> a; arr.insert(a);}
	dp[0] = 2;
	int chance = 0;
	for (int i = 1; i <= k; i++) {
		if (arr.find(i) != arr.end())
			dp[i] = 0;
		else for (auto j : arr) {
				if (j < i && dp[i - j] == 1)dp[i] = 0;
			}
		if (dp[i] == -1) {
			dp[i] = 1;
			// cout << "not " << i << endl;
			// if (chance == 1)dp[i] = 0;
			// else dp[i] = 1;
		}
		// if (chance == 1)chance = 0;
		// else chance = 1;
	}
	// for (auto i : dp)cout << i << " "; cout << endl;
	if (dp[k])cout << "Second";
	else cout << "First";
	// cout << dp[k];
}