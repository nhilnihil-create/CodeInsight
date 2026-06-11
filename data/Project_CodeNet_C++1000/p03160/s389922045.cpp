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
	int n; cin >> n;
	int a[n];
	rep(i, 0, n) cin >> a[i];
	int dp[n];
	if (n == 2) {
		cout << abs(a[0] - a[1]);
		return;
	}
	dp[n - 1] = 0; dp[n - 2] = abs(a[n - 1] - a[n - 2]);
	for (int i = n - 3; i >= 0; i--) {
		dp[i] = min(abs(a[i] - a[i + 1]) + dp[i + 1], abs(a[i] - a[i + 2]) + dp[i + 2]);
	}
	cout << dp[0];
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