#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define pb push_back
using namespace std;
int dp[100001];
int n;
int solve(int *a, int s)
{
    if(s==0)
        return 0;
    if(s<0)
        return 1;
    if(dp[s]!=-1)
        return dp[s];
    for(int i=0;i<n;i++)
    {
        if(solve(a,s-a[i])==0)
            return dp[s]=1;
    }
    return dp[s]=0;
}
int32_t main()
{
    int t;
    //cin>>t;
    //while(t--)
    {   
        int k;
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
        int a[100001];
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(solve(a,k))
            cout<<"First";
        else
            cout<<"Second";
    }
}




