#include<bits/stdc++.h>
using namespace std;
//vector<vector<long long int> > dp(100001,vector<long long int>(4));
long long int dp[100001][4];
long long int n;
long long int gen(int i,int p,vector<vector<long long int> >&arr)
{
    long long int ans=INT_MIN;
    if(i>=n)
        return 0;
    if(dp[i][p]!=-1)
        return dp[i][p];
    if(p==0)
    {
        ans=max(ans,arr[i][1]+gen(i+1,1,arr));
        ans=max(ans,arr[i][2]+gen(i+1,2,arr));
    }
    else if(p==1)
    {
        ans=max(ans,arr[i][0]+gen(i+1,0,arr));
        ans=max(ans,arr[i][2]+gen(i+1,2,arr));
    }
    else if(p==2)
    {
       ans=max(ans,arr[i][0]+gen(i+1,0,arr));
       ans=max(ans,arr[i][1]+gen(i+1,1,arr));

    }
    else{
        ans=max(ans,arr[i][0]+gen(i+1,0,arr));
        ans=max(ans,arr[i][1]+gen(i+1,1,arr));
        ans=max(ans,arr[i][2]+gen(i+1,2,arr));
    }
    return dp[i][p]=ans;

}
int main()
{
    //int n;
    cin>>n;
    vector<vector<long long int>> arr(n,vector<long long int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    //input part has been done
    memset(dp,-1,sizeof(dp));

    long long ans=gen(0,3,arr);
    cout<<ans;

}
