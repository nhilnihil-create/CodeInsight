#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
#define pii pair<ll int, ll int>
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define repi(i, n) for(ll i=0; i<n; i++)
#define rep(i, a, b) for(ll i=a; i<=b; i++)
#define M 1000000007
#define INF 1e18

using namespace std;

int main() {
    ios
    ll n; cin>>n;
    vector <ll> a(n);
    repi(i, n) cin>>a[i];
    ll pre[n];
    pre[0] = a[0];
    rep(i, 1, n-1) pre[i] = pre[i-1] + a[i];
    ll dp[n][n];
    repi(i, n) dp[i][i] = 0;
    repi(i, n-1) dp[i][i+1] = a[i]+a[i+1];
    rep(j, 2, n-1){
        for(ll i=0; i+j<n; i++){
            dp[i][i+j] = INF;
            rep(k, i, i+j){
                dp[i][i+j] = min(dp[i][i+j], dp[i][k] + pre[i+j] - (i>0 ? pre[i-1] : 0) + dp[k+1][i+j]);
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}
