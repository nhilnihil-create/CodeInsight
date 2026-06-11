#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
int h[10] = {0,2,5,5,4,5,6,3,7,6};

int main(){
    int n,m;
    cin >> n >> m;
    ve<char> a(m);
    rep(i,m){
        cin >> a[i];
    }
    ve<string> dp(n+10);
    dp[0] = "";
    rep(i,m){
        dp[h[a[i]-'0']] = max(dp[h[a[i]-'0']],(string)""+a[i]);
    }
    rep(i,n+1){
        rep(j,m){
            if(dp[i] == "") continue;
            if(i+h[a[j]-'0'] >= n+1) continue;
            if(dp[i + h[a[j]-'0']].size() > dp[i].size()+1) continue;
            if(dp[i + h[a[j]-'0']].size() < dp[i].size()+1){
                dp[i+h[a[j]-'0']] = dp[i] + a[j];
                continue;
            }
            dp[i+h[a[j]-'0']] = max(dp[i+h[a[j]-'0']], dp[i] + a[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}