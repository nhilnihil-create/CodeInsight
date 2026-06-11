#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;

const int MX=200010,INF=1001001001,mod=1e9+7;
int dp[MX];

int main(){
    int n;
    cin>>n;
    rep(i,MX)dp[i]=INF;
    dp[0]=0;
    rep(i,n){
        for(int j=1; j<=100000; j*=6){
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
        for(int j=1; j<=100000; j*=9){
            dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }
    cout<<dp[n]<<endl;
}