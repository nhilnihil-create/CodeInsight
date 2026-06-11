#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int dp[100001];

int solve(int a[], int n)
{
    if(n<2)
    {
        return 0;
    }
    
    if(dp[n] != -1)
    return dp[n];

    if(n==2)
        dp[n] = abs(a[n]-a[n-1]) + solve(a,n-1);

    if(n >2)
        dp[n] = min(abs(a[n]-a[n-1]) + solve(a,n-1),abs(a[n]- a[n-2]) +solve(a,n-2));

    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
   
   int l=solve(a,n);
    cout<<l<<"\n";

    return 0;
}
