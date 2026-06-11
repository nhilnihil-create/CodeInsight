#include <bits/stdc++.h>
using namespace std;

#define d double

d coin(vector<d> p, int n){
    vector<vector<d>> dp(n+1, vector<d>(n+1, 0.0));
    dp[0][0]=1.0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0) dp[i][j] = dp[i-1][j]*(1-p[i-1]);
            else dp[i][j] = dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1-p[i-1]);
        }
    }
    d ans = 0.0;
    for(int i=(n+1)/2; i<=n; i++) ans+=dp[n][i];
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<d> p(n);
    for(int i=0; i<n; i++) cin>>p[i];
    cout<<setprecision(10)<<coin(p, n);
    return 0;
}
