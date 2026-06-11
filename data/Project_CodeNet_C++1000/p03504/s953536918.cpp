#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    ll N,C; cin>>N>>C;
    vector<vector<int>> imos(31,vector<int>(100010,0));
    rep(i,N){
        ll s,t,c; cin>>s>>t>>c;
        imos[c][s]++;
        imos[c][t]--;
    }
    rep1(i,C){
        rep1(t,100001)imos[i][t] += imos[i][t-1];
    }
    vector<int> dp(100010,0);
    rep1(i,C){
        rep1(t,100001){
            if(imos[i][t-1]==0&&imos[i][t]==1)dp[t-1]++;
            if(imos[i][t-1]==1&&imos[i][t]==0)dp[t]--;
        }
    }
    int res = 0;
    rep1(t,100001)dp[t] += dp[t-1], res = max(res,dp[t]);
    cout<<res<<endl;
}