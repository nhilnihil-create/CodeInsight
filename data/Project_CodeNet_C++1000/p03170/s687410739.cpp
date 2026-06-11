#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,k;
int a[100005];
int dp[100005];

int solve(int x)
{
    if(dp[x]!=-1)
        return dp[x];
    int &ans=dp[x];
    ans=1;
    for(int i=0;i<n;i++)
        if(x-a[i]>=0)
            ans=min(ans,solve(x-a[i]));
    ans^=1;
    return ans;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    cin>>n>>k;
    //cout<<n<<" "<<k<<"\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int ans=0;
    ans=solve(k);
    cout<<(ans?"First":"Second");    
}
