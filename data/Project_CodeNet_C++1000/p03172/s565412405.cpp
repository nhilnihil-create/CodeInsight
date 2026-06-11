#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _cin      ios_base::sync_with_stdio(0);  cin.tie(0);
#define READ      freopen("input.txt", "r", stdin);
#define WRITE     freopen("output.txt", "w", stdout);
#define endl "\n"
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>=b;--i)
#define mp make_pair
#define hell 1000000007
#define vvll vector<vector<ll> >
#define vll vector<ll>
#define mll map<ll,ll>
#define sz(x) (ll)x.size()
#define sll set<ll>
#define pll pair<ll,ll>
#define F first
#define S second
const ll MAX = 1000004;
const ll INF = 1e18L + 5;


int main() {

	_cin
	// READ
	// WRITE
	ll n, k;
	cin >> n >> k;
	ll a[n + 1];
	rep(i, 1, n + 1) cin >> a[i];
	ll dp[n + 1][k + 1];
	dp[0][0] = 1;
	rep(i, 1, k + 1) dp[0][i] = 0;
	rep(i, 1, n + 1) {
		vll sum(k + 1, 0);

		sum[0] = dp[i - 1][0] ;
		rep(j, 1, k + 1) sum[j] = (sum[j - 1] + dp[i - 1][j]) % hell ;
		rep(j, 0, k + 1) {
			if (j <= a[i]) {
				dp[i][j] = sum[j];
			} else {
				ll s = (j - a[i] - 1);
				dp[i][j] = (sum[j] - sum[s] + hell) % hell  ;

			}
		}

		sum.clear();

	}

	cout << dp[n][k] % hell << endl;





}