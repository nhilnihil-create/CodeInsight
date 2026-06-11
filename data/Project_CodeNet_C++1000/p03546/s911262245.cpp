#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int H, W; cin >> H >> W;
    vector<vector<ll>> dp(10, vector<ll>(10, INF));
    rep(i, 10){
        rep(j, 10){
            cin >> dp[i][j];
        }
    }
    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }

    ll ans = 0;
    rep(i, H){
        rep(j, W){
            int c; cin >> c;
            if(c != -1 && c != 1){
                ans += dp[c][1];
            }
        }
    }
    cout << ans << endl;
}
