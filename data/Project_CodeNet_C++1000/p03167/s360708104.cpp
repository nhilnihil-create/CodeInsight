#include<bits/stdc++.h>
using namespace std;

// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int H,W; cin>>H>>W;
    vector<string> S(H);
    rep(i,H)cin>>S[i];
    vector<vector<ll>> dp(H,vector<ll>(W,0));
    dp[0][0] = 1;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='#')continue;
            if(i>0&&S[i-1][j]=='.') (dp[i][j] += dp[i-1][j])%=MOD;
            if(j>0&&S[i][j-1]=='.') (dp[i][j] += dp[i][j-1])%=MOD;
        }
    }
    cout<<dp[H-1][W-1]%MOD<<endl;
}