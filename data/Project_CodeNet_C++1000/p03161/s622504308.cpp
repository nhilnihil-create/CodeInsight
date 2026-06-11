#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000000;
int main(){
    ll n, k; cin >> n >> k;
    vector<ll> h(n);
    for(ll i=0; i<n; ++i){cin >> h[i];}
    vector<ll> dp(n, INF); dp[0] = 0; 
    for(ll i=1; i<n; ++i){
        for(ll j=1; j<=min(i,k); ++j){
            if(j==1){dp[i] = abs(h[i]-h[i-j]) + dp[i-j];}
            else{dp[i] = min(dp[i-j] + abs(h[i]-h[i-j]), dp[i]);}
          	//for(int k=0; k<n; ++k){cout << dp[k] << ",";} cout << endl;
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}