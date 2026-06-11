#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;

int main(){
    int H,W; cin>>H>>W;
    vector<string> S(H);
    rep(i,H)cin>>S[i];
    vector<vector<ll>> dp(H,vector<ll> (W,0));
    dp[0][0]=1;
    rep(h,H){
        rep(w,W){
            if(S[h][w]=='#')continue;
            if(h>0&&S[h-1][w]=='.')(dp[h][w]+=dp[h-1][w]%MOD)%MOD;
            if(w>0&&S[h][w-1]=='.')(dp[h][w]+=dp[h][w-1]%MOD)%MOD;
        }
    }
    cout<<dp[H-1][W-1]%MOD<<endl;
}