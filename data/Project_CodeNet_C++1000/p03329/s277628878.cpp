#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
#define chmin(x,y) x = min(x,y)

int main(){
    int n; cin>>n;
    int dp[100005];
    rep(i,100005) dp[i]=1e9;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int a=1;a<=i;a*=6) chmin(dp[i], dp[i-a]+1);
        for(int b=1;b<=i;b*=9) chmin(dp[i], dp[i-b]+1);
    }
    cout << dp[n] << endl;
}