
#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
int dp[100][100005];
int arr[100];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<=arr[0];i++)
    {
        dp[0][i]=1;
    }
    for(int i=1;i<n;i++)
    {
        //dp[i]
        vector<int>prefix(k+1);
        prefix[0]=dp[i-1][0];
        for(int j=1;j<=k;j++)
        {
            prefix[j]=(prefix[j-1]+dp[i-1][j])%m;
        }
        for(int j=0;j<=k;j++)
        {
            if(j>arr[i])
            dp[i][j]=(prefix[j]+m-prefix[j-arr[i]-1])%m;
            else
            dp[i][j]=prefix[j];
        }
    }
    cout<<dp[n-1][k];
    return 0;
}
