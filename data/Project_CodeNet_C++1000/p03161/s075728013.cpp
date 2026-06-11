#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll>h(n);
    for(ll i=0;i<n;i++) cin >> h[i];
    vector<ll>dp(n+1,MOD);
    dp[0]=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=k;j++){
            if(i-j<0) continue;
            dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    cout << dp[n-1] << endl;
}