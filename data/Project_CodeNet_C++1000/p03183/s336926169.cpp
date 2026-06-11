#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(in) in.begin(),in.end()
#define fi first
#define se second
using namespace std;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using ll = long long;
using pp = pair<pair<ll,ll>,ll>;

bool comp(pp a, pp b){ return a.fi.fi + a.fi.se < b.fi.fi + b.fi.se; }

int main(){
    int n; cin >> n;
    vector<pp> data(n); rep(i,n) cin >> data[i].fi.fi >> data[i].fi.se >> data[i].se;
    sort(all(data), comp);
    vector<vector<ll>> dp(n+1,vector<ll>(20001,0ll));
    rep(i,n) rep(j,20001){
        chmax(dp[i+1][j], dp[i][j]);
        if(j >= 1) chmax(dp[i+1][j], dp[i+1][j-1]);
        if(j >= data[i].fi.fi && j - data[i].fi.fi <= data[i].fi.se)
        chmax(dp[i+1][j], dp[i][j-data[i].fi.fi] + data[i].se);
    }
    ll ans = 0;
    rep(i,20001) chmax(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}