#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int H,W; cin>>H>>W;
    int dp[10][10];
    rep(i,10){
        rep(j,10){
            cin>>dp[i][j];
        }
    }
    rep(k,10)rep(i,10)rep(j,10){
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }
    int ans=0;
    rep(i,H)rep(j,W){
        int b; cin>>b;
        if(b!=-1)ans+=dp[b][1];
    }
    cout<<ans<<endl;
    return 0;
}