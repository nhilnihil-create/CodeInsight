#include<iostream>
using namespace std;
int solve(int a[],int i,int n,int dp[])
{
    if(i>=n)
    {
        return dp[i]=0;
    }
    else if(dp[i]!=-1)
    {
        return dp[i];
    }
    else
    {
        return dp[i]=min(abs(a[i+1]-a[i])+solve(a,i+1,n,dp),abs(a[i+2]-a[i])+solve(a,i+2,n,dp));
    }
}
int main()
{
    int n,i;
    cin>>n;
    int m[n];
    int dp[100005];
    for(i=0;i<100005;i++)
    {
        dp[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    cout<<solve(m,0,n-1,dp)<<endl;
}
