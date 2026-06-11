#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define F first
#define S second
#define pb push_back
#define M 1000000007
#define inf 1e18
#define jam(x) cout<<"Case #"<<x<<": "

int32_t main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n, k = 3;
	int i, j;
	cin >> n;
	vector< vector<int> > mat(n, vector<int>(k));
	vector< vector<int> > dp(n, vector<int>(k, 0));
	for (i = 0; i < n; i++) {
		for (j = 0; j < k; j++) {
			cin >> mat[i][j];
		}
	}
	for (i = 0; i < n; i++) dp[0][i] = mat[0][i];
	for (i = 1; i < n; i++) {
		for (j = 0; j < k; j++) {
			for (int op = 0; op < k; ++op) {
				if (op != j) {
					dp[i][j] = max(dp[i][j] , mat[i][j] + dp[i - 1][op]) ;
				}
			}

		}
	}

	int ans = 0;
	for (i = 0; i < k; i++) {
		ans = max( ans , dp[n - 1][i] );
	}
	cout << ans << endl;

	return 0;
}