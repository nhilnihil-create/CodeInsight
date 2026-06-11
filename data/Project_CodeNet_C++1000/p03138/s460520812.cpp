#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

ll keta(ll i){
    ll res = 0;
    while(i>0){
        i /= 2;
        res++;
    }
    return res;
}

int main(){
    ll n,k;
    cin >> n >> k;
    ve<ll> a(n);
    rep(i,n) cin >> a[i];
    ve<ve<ll>> dp(41,ve<ll>(2,-1));
    dp[0][0] = 0;
    rep(i,40){
        ll id = pow(2,(39-i));
        ll cnt = 0;
        rep(j,n){
            if(a[j] & id) cnt++;
        }
        if(k&id){
            dp[i+1][0] = dp[i][0] + id*(n-cnt);
            if(dp[i][1] == -1) dp[i+1][1] = dp[i][0] + id*cnt;
            else{
                dp[i+1][1] = dp[i][1] + id*max(cnt,n-cnt);
                dp[i+1][1] = max(dp[i+1][1], dp[i][0] + id*cnt);
            }
        }else{
            dp[i+1][0] = dp[i][0] + id*cnt;
            if(dp[i][1] == -1) dp[i+1][1] = -1;
            else dp[i+1][1] = dp[i][1] + id*max(cnt,n-cnt);
        }
    }
    cout << max(dp[40][0],dp[40][1]) << endl;
    return 0;
}