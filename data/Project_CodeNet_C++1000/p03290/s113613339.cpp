#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    ll d,g; cin>>d>>g;
    g/=100;
    vector<ll> p(d);
    vector<ll> c(d);
    rep(i,0,d){
        ll x,y; cin>>x>>y;
        y/=100;
        p[i]=x; c[i]=y;
    }
    vector<vector<ll>> dp(d+1,vector<ll> (430000,INF));
    dp[0][0]=0;
    rep(i,0,d){
        rep(pnt,0,210000){
            rep(k,0,p[i]){
                chmin(dp[i+1][pnt+(i+1)*k],dp[i][pnt]+k);
            }
            chmin(dp[i+1][pnt+(i+1)*p[i]+c[i]],dp[i][pnt]+p[i]);
        }
    }
    ll ans=INF;
    rep(i,g,430000){
        chmin(ans,dp[d][i]);
    }
    cout<<ans<<endl;
}