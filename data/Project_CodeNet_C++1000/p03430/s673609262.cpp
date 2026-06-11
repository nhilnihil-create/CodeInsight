#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)

template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; int K; cin >> S >> K;
    int n=S.size();
    int dp[n+1][n+1][K+1];
    rep(i,n+1) rep(j,n+1) rep(k,K+1) dp[i][j][k]=0;
    rep(i,n) dp[i][i+1][0]=1;
    for (int j=2;j<=n;++j)
        for (int i=0;i+j<=n;++i)
            for (int k=0;k<=K;++k){
                chmax(dp[i][i+j][k],max(dp[i+1][i+j][k],dp[i][i+j-1][k]));
                if (S[i]==S[i+j-1]) chmax(dp[i][i+j][k],dp[i+1][i+j-1][k]+2);
                else if (k<K) chmax(dp[i][i+j][k+1],dp[i+1][i+j-1][k]+2);
    }
    int ans=0;
    rep(k,K+1) chmax(ans,dp[0][n][k]);
    cout << ans << endl;
}