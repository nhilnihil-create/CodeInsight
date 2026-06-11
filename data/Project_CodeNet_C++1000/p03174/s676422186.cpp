#include<iostream>
#include<bits/stdc++.h>

#define mod 1000000007
#define int long long
using namespace std;

vector<vector<int> > compatible(22, vector<int>(22));
int n;
int dp[22][(1 << 22)];

int solve(int i, int womenSubset) {

	if (i == n + 1) {

		if (womenSubset == 0)
			return 1;
		return 0;
	}

	if (dp[i][womenSubset] != -1)
		return dp[i][womenSubset];

	int ans = 0;
	for (int women = 0; women < n; women++) {

		bool available = ( (womenSubset & (1 << women)) == 0 ? 0 : 1);
		if (available && compatible[i-1][women])
			ans = (ans + solve(i + 1, womenSubset ^ (1 << women))) % mod;

	}

	return dp[i][womenSubset] = ans;
}


int32_t main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> compatible[i][j];
		}
	}

	memset(dp, -1, sizeof dp);
	cout << solve(1, ((1 << n) - 1)) << endl;
















}