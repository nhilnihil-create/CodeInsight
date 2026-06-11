#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n;cin>>n;
    int a[n+1];
    int csum[n+1];
    a[0] = 0;
    csum[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        csum[i] = a[i] + csum[i-1];
        }
    int dp[n+1][n+1];
    memset(dp,0,sizeof dp);
    int row,temp;
    for(int col=2;col<=n;col++){
        row=1;
        temp=col;
        while(row<=n && temp<=n){
            dp[row][temp] = 9999999999999999;
            for(int k=row;k<temp;k++){
               dp[row][temp] = min(dp[row][temp],dp[row][k] + dp[k+1][temp] + csum[temp] - csum[row-1]); 
            }
            row++;
            temp++;
        }
    }
    cout<<dp[1][n];

}
