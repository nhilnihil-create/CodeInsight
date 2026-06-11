#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>> dp(k+1, vector<int>(2));
    for(int i=0;i<=k;i++){
        int m=0;
        dp[i][0]=2;
        dp[i][1]=-2;    
        for(int j=0;j<n;j++){
            if(a[j]<=i){
                dp[i][0] = min(dp[i][0] , dp[i-a[j]][1]);
                dp[i][1] = max(dp[i][1] , dp[i-a[j]][0]);
                m++;
            }
        }
        //if has no possible moves, not sure with k=0 though
        if(m==0){
            dp[i][0]=1;
            dp[i][1]=0;
        }
        //cout<<dp[i][0] << " " << dp[i][1]<<"\n";
    }
    cout<<(dp[k][0]?"Second":"First")<<"\n";
    return 0;
}