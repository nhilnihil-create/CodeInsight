#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=1e9+7;
int n, a[21][21], dp[1<<21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) cin >> a[i][j];
	dp[0]=1;
	for (int mask=0; mask<(1<<n); ++mask) {
		int k=__builtin_popcount(mask); //we are on kth man with mask (women) taken
		for (int j=0; j<n; ++j)
			if (!(mask&(1<<j))&&a[k][j])
				dp[mask|(1<<j)]=(dp[mask|(1<<j)]+dp[mask])%MOD;
	}
	cout << dp[(1<<n)-1];
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
