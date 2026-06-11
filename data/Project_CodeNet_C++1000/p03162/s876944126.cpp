#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
#define endl '\n'
#define rep(i,a,n) for (int i=a;i<n;i++)
#define pb push_back
#define mm(X) memset((X), 0, sizeof((X)))
#define deb(x) cout<<#x<<" "<<x<<endl;



void solve() {
	int n;
	cin >> n;
	int a[n][3];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	if (n == 1) {
		int max1 = a[0][0];
		rep(i, 1, 3) {
			max1 = max(max1, a[0][i]);
		}
		cout << max1;
		return;
	}
	int dp[n][3];
	mm(dp);
	rep(i, 0, 3) {
		dp[0][i] = a[0][i];
	}
	int ans = INT_MIN;
	for (int i = 1; i < n; i++) {

		for (int j = 0; j < 3; j++) {
			if (j == 0)
				dp[i][j] = a[i][j] + max(dp[i - 1][j + 1], dp[i - 1][j + 2]);
			else if (j == 2)
				dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j - 2]);
			else
				dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j + 1]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	// cout << endl << dp[n - 1][0] << " " << dp[n - 1][1] << " " << dp[n - 1][2];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int tc; cin >> tc;
	// for (int t = 1; t <= tc; t++) {
	//cout << "Case #" << t  << ": ";
	solve();
	// }
}