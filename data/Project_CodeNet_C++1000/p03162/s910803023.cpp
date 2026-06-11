#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(3));
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>dp[i][j];
    for(int i=1;i<n;i++){
        dp[i][0]+=max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]+=max(dp[i-1][2],dp[i-1][0]);
        dp[i][2]+=max(dp[i-1][1],dp[i-1][0]);
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    solve(); cout<<endl;
    return 0;
}