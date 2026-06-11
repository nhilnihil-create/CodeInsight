#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

const int INF = 1e8;

int main(){
    int n;
    cin >> n;
    ve<int> dp(n+10,INF);
    dp[0] = 0;
    rep(i,n)dp[i+1] = dp[i] + 1;
    int k = 6;
    while(k<=n){
        rep(i,n-k+5){
            dp[i+k] = min(dp[i+k], dp[i]+1);
        }
        k*= 6;
    }
    k = 9;
    while(k<=n){
        rep(i,n-k+5){
            dp[i+k] = min(dp[i+k], dp[i]+1);
        }
        k*= 9;
    }
    cout << dp[n] << endl;
    return 0;
}
