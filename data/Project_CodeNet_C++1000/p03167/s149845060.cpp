#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main() {
    int h,w;
    cin >> h >> w;
    char arr[h][w];
    for(int i = 0;i<h;i++) for(int j =0 ;j<w;j++) cin >> arr[i][j];
    vector<vector<int>> dp(h,vector<int>(w,0));
    dp[0][0] = 1;
    for(int i = 0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==0&&j==0);
            else if(arr[i][j]  == '#' ) dp[i][j] = 0;
            else if(i==0) dp[i][j] = dp[i][j-1]%mod;
            else if(j==0) dp[i][j] = dp[i-1][j]%mod;
            else dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
        }
    }
    cout << dp[h-1][w-1];
    return 0;
}