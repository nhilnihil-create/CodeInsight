#include<bits/stdc++.h>
using namespace std;
long long int dp[100001][3];
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    //input part has been done
    //now initialization for day 1
    dp[1][0]=arr[0][0];
    dp[1][1]=arr[0][1];
    dp[1][2]=arr[0][2];
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=arr[i-1][0]+max(dp[i-1][1],dp[i-1][2]);

        dp[i][1]=arr[i-1][1]+max(dp[i-1][0],dp[i-1][2]);

        dp[i][2]=arr[i-1][2]+max(dp[i-1][1],dp[i-1][0]);
    }
    long long int ans=max(dp[n][0],max(dp[n][1],dp[n][2]));
    cout<<ans<<endl;
}
