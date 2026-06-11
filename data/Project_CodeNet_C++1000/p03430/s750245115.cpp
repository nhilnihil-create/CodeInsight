#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll p = 998244353;

string s;
int kk, n;

int dp[305][305][305];

int comp(int i, int j, int k) {
	if (k < 0)
		return -1000;
	if (i > j)
		return 0;

	if (dp[i][j][k] != -1)
		return dp[i][j][k];

	if (i == j) {
		dp[i][j][k] = 1;
		return dp[i][j][k];
	}

	if (s[i] == s[j]) {
		dp[i][j][k] = 2 + comp(i+1, j-1, k);
		return dp[i][j][k];
	}

	dp[i][j][k] = comp(i+1, j, k);
	dp[i][j][k] = max(dp[i][j][k], comp(i, j-1, k));
	dp[i][j][k] = max(dp[i][j][k], 2 + comp(i+1, j-1, k-1));

	// cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
	return dp[i][j][k];
}

int main() {
	cin >> s >> kk;
	n = s.length();

	for (int i = 0; i < 305; ++i)
		for (int j = i; j < 305; ++j)
			for (int a = 0; a <= kk; ++a)
				dp[i][j][a] = -1;

	cout << comp(0, n-1, kk) << endl;
}