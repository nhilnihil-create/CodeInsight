#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>>c(10,vector<ll>(10));
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            cin >> c[i][j];
        }
    }
    vector<vector<ll>>dp=c;
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            for(ll k=0;k<10;k++){
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            ll a;
            cin >> a;
            if(a>=0) ans+=dp[a][1];
        }
    }
    cout << ans << endl;
}
