#include <bits/stdc++.h>
using namespace std;
long long int s[1000];
long long int dp[500][500];
void precompute(long long int arr[],int n)
{
    s[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        s[i]=s[i-1]+arr[i];
    }
}
long long int  solve(long long int arr[],int n,int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
   long long int ans=9223372036854775807;
    for(int k=i;k<j;k++)
    {
        ans=min(ans,solve(arr,n,i,k)+solve(arr,n,k+1,j)+(s[k]-s[i]+arr[i])+(s[j]-s[k+1]+arr[k+1]));
    }
    return dp[i][j]=ans;
}

int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    long long int  arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    precompute(arr,n);
    long long int ans=solve(arr,n,0,n-1);
    cout<<ans<<endl;
}