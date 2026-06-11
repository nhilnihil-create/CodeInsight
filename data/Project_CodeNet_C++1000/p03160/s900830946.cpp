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
	std::vector<ll> arr(n + 1);
	for (ll i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	std::vector<ll> dp(n + 1);
	dp[0] = 0;
	dp[1] = abs(arr[1] - arr[0]);
	for (ll i = 2; i < n; ++i)
	{
		ll onejump = dp[i - 1] + abs(arr[i] - arr[i - 1]);
		ll twojump  = dp[i - 2] + abs(arr[i] - arr[i - 2]);
		dp[i] = min(onejump, twojump);
	}
	cout << dp[n - 1] << endl;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	// cin >> t;
	while (t--)
		solve();

}




