// this is the memoized code

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
ll n;
ll arr[100005][4];
ll dp[100005][4];

ll maxpoints(ll day, ll act) {
	if (day == n) {
		return 0;
	}
	if (dp[day][act] != -1)
		return dp[day][act];

	ll maxi = 0;
	if (act == 0) {
		maxi = max(maxi, arr[day][1] + maxpoints(day + 1, 1));
		maxi = max(maxi, arr[day][2] + maxpoints(day + 1, 2));
		maxi = max(maxi, arr[day][3] + maxpoints(day + 1, 3));
	}

	else if (act == 1) {
		maxi = max(maxi, arr[day][2] + maxpoints(day + 1, 2));
		maxi = max(maxi, arr[day][3] + maxpoints(day + 1, 3));

	}
	else if (act == 2) {
		maxi = max(maxi, arr[day][1] + maxpoints(day + 1, 1));
		maxi = max(maxi, arr[day][3] + maxpoints(day + 1, 3));
	}
	else if (act == 3) {
		maxi = max(maxi, arr[day][1] + maxpoints(day + 1, 1));
		maxi = max(maxi, arr[day][2] + maxpoints(day + 1, 2));
	}

	return dp[day][act] = maxi;
}

void solve() {
	cin >> n;

	for (ll i = 0; i < n; i++) {
		for (ll j = 1; j < 4; ++j)
		{
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << maxpoints(0, 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while (t--)
		solve();

}




