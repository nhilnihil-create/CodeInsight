#include<bits/stdc++.h>
using namespace std;
#define I INT32_MAX
#define IM INT_MIN
#define MOD 1000000007
#define ll long long
#define lli long long int
#define rep(i,n) for (int i = 0; i < n; i++)
#define repk(i,k,n) for (int i = k; i <= n; i++)
#define repr(i,k,n) for (int i = k; i >= n; i--)
#define all(v) (v).begin(),(v).end()
typedef vector<int> vi;
typedef set<int> si;
ll dp[100005];
ll arr[100005];
ll n;

ll mincost(ll i) {
	// int n = sizeof(arr);
	if (i == n - 1) {
		return 0;

	}
	if (i >= n) return INT_MAX;

	if (dp[i] != -1) {
		return dp[i];
	}
	ll onejump = mincost(i + 1) + abs(arr[i] - arr[i + 1]);
	ll twojump = INT_MAX;
	if (i + 2 < n) {
		twojump = mincost(i + 2) + abs(arr[i] - arr[i + 2]);

	}
	return dp[i] = min(onejump, twojump);

}

void solve() {
	// int n;
	cin >> n;

	memset(dp, -1, sizeof(dp));
	rep(i, n) {
		cin >> arr[i];
	}
	cout << mincost(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while (t--)
		solve();

	return 0;

}




