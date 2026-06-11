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


void solve() {
	ll n;
	cin >> n;
	cout << fixed;
	cout << setprecision(10);
	vector<double> arr(n);
	for (ll i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	double dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (ll i = 1; i <= n; ++i)
	{
		for (ll j = 0; j <= i; ++j)
		{
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] * (1 - arr[i - 1]);
			}
			else {
				dp[i][j] = dp[i - 1][j] * (1 - arr[i - 1]) + dp[i - 1][j - 1] * (arr[i - 1]);
			}
		}
	}
	double ans = 0.0;
	for (ll i = n; i > ( n / 2); i--) {
		ans = ans + dp[n][i];
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while (t--)
		solve();

}



