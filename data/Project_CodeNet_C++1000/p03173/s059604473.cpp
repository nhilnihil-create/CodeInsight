#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define INF (ll) (1e18)
#define mod (ll) (1e9 + 7)
#define endl "\n"
#define tt ll testcase; cin>>testcase; while(testcase--)
 
const int mxn = 1*(1e5) + 5;
ll n, m;
 
void solve(){
	cin >> n;
	ll a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	ll pref[n+1] = {};
	//// sum [l][r] = pref[r] - pref[l-1]
	for(int i=0; i<n; i++) {
		pref[i+1] = pref[i] + a[i];
	}
	// ll dp[n][n] = {};
	vector<vector<ll>>dp(n, vector<ll>(n, INF));
	for(int l=n-1; l>=0; l--) {
		dp[l][l] = 0;
		for(int r = l; r<n; r++) {
			// if(r-l == 1) {
			// 	dp[l][r] = a[r] + a[l];
			// } else {
				// dp[l][r] = min(a[l] + dp[l+1][r] + pref[r+1]-pref[l+1], a[r] + dp[l][r-1] + pref[r]-pref[l]);
				for(int i = l; i<r; i++) {
					dp[l][r] = min(dp[l][i] + dp[i+1][r] - pref[l] + pref[r+1], dp[l][r]);	
				}
				// if((r-l) == 1) dp[l][r] = a[r] + a[l];
			// }
		}
	}
	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[0][n-1];
}
 
int main(){
    fast;
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif 
     // tt
        solve();
    return 0;
}