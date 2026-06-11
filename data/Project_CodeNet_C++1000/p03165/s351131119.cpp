#include<bits/stdc++.h>
using namespace std;

// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 998244353
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    string s,t; cin>>s>>t;
    int ss = s.size(), tt = t.size();
    vector<vector<int>> dp(ss+10,vector<int>(tt+10,0));//dp[i][j] = i文字j文字の最長の長さ
    rep(i,ss){
        rep(j,tt){
            if(s[i]==t[j]) dp[i+1][j+1] = max(dp[i][j]+1,dp[i+1][j+1]);
            dp[i+1][j+1] = max({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]});
        }
    }
    int l = dp[ss][tt];
    int is = ss, it = tt;
    string res = "";
    while(is>0&&it>0){
        if(s[is-1]==t[it-1]){
            res  = res + s[is-1];
            is--; it--;
        }else if(dp[is][it] == dp[is][it-1]){
            it--;
        }else is--;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}