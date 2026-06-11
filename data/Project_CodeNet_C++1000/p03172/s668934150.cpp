#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define INF (ll) (1e9)
#define mod (ll) (1e9 + 7)
#define endl "\n"
#define tt ll testcase; cin>>testcase; while(testcase--)
 
const int mxn = 1*(1e5) + 5;
ll n, m;


// 2 methods:
// m-1:  O(N*M*M)

// m-2: use prefix sums to add value over interval
		// O(N*M)
 
void solve(){	
	cin >> n >> m;
	ll a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}	
	ll dp[m+1] = {};
	dp[0] = 1;
	for(int i=0; i<n; i++) {
		ll upto = a[i];
		ll sum[m+2] = {};
		for(int j = m; j>=0; j--) {
			// for(int l = j+1; l<=min(upto+j, m); l++) {
			// // for(int l = min(j+upto, m); l > j; l--) {
			// 	dp[l] += dp[j];
			// 	if(dp[l] > mod) {
			// 		dp[l] -= mod;
			// 	}
			// }
			sum[min(upto+j, m)+1] -= dp[j];
			sum[j+1] += dp[j]; 
		}
		ll s=0;
		for(int i=0; i<=m; i++) {
			s += sum[i];
			// s %= mod;
			dp[i] += s;
			dp[i] %= mod;
		}
	}
	// for(int i=0; i<=m; i++) {
	// 	cout << dp[i] << " ";
	// }
	cout << dp[m];
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