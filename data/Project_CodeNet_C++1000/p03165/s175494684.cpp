#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 998244353
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    string S,T; cin>>S>>T;
    int s = S.size(),t = T.size();
    vector<vector<int>> dp(s+1,vector<int>(t+1,0));//dp[i][j] = 初めi,j文字の最長部分列。
    rep(i,s){
        rep(j,t){
            if(S[i]==T[j])dp[i+1][j+1]=max({dp[i][j+1],dp[i+1][j],dp[i][j]+1});
            else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    string res = "";
    int i = s, j = t;
    while(i>0&&j>0){
        if(S[i-1]==T[j-1]){
                res += S[i-1];
                i--; j--;
        }else if(dp[i-1][j]==dp[i][j]){
            i--;
        }else j--;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}
