#include <iostream>
#include<cstring>
#include<iomanip>
using namespace std;

double probability(double p[],int n){
    double dp[n+1][n+1];
    memset(dp,0.0,sizeof(dp));
    dp[0][0] = 1.0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j==0)
            dp[i][j] = dp[i-1][j]*(1.0-p[i-1]);
            else
            dp[i][j] = dp[i-1][j]*(1.0-p[i-1]) + dp[i-1][j-1]*p[i-1];
        }
    }
    double ans = 0.0;
    for(int i=(n+1)/2;i<=n;i++){
        ans += dp[n][i];
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    double p[n];
    for(int i=0;i<n;i++)
    cin>>p[i];

    cout<<setprecision(10)<<probability(p,n);

    return 0;
}