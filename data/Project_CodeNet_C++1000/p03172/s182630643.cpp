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
 
void solve(){
    cin >> n >> m;
    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];

    ll dp[n+1][m+1] = {};
    dp[0][0] = 1;
    vector<ll>sum(m+2, 0);
    // sum[0] = 1;
    for(ll i=1; i<=n; i++) {
        ll s = 0;
        for(int j=0; j<=m; j++) {
            s += dp[i-1][j];
            sum[j+1] = s;
        }
        for(ll j=0; j<=m; j++) {
            // for(ll k=0; k<=min(j, a[i-1]); k++) {
            //     dp[i][j] += dp[i-1][j-k];
            //     dp[i][j] %= mod;
            // }
            dp[i][j] = sum[j+1] - sum[j-min(j, a[i-1])];
            dp[i][j] %= mod;
        }
    }
    // for(int j=0; j<=n; j++)
    // for(int i=0; i<=m; i++) {
    //     cout<<dp[n][i]<<" ";
    // }
    cout << dp[n][m];
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