#include <bits/stdc++.h> 
#include <unordered_map> 
using namespace std; 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    int n=0;
    cin>>n;
    double p[n+1];
    memset(p,0,sizeof(p));
    for(int i=1;i<=n;i++) cin>>p[i];
    double dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if (j==0) dp[i][j]=dp[i-1][j]*(1.0-p[i]);
            else dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++)
    //        cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    double result=0;
    cout.precision(10);
    for(int j=(n+1)/2;j<=n;j++)
       result+=dp[n][j];
    cout<<result<<endl;
	return 0;
} 