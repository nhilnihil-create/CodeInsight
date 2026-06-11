#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define li long
#define pb push_back
#define mem(arr,x) memset(arr,x,sizeof(arr))

int n,mat[22][22];
int dp[1<<22];

int totalWays(int manCount,int mask)
{
    if(manCount==n)  return 1;
    if(dp[mask]!=-1)  return dp[mask];
    ll i,ans=0;
    for(i=1;i<=n;i++)
    {
        int flag = mask & (1<<i);
        if(mat[manCount][i-1]==1 && flag==0)
        {
            int newMask = mask|(1<<i);
            ans+=totalWays(manCount+1,newMask)%MOD;
        }
    }
    dp[mask]=ans%MOD;
    return ans%MOD;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    mem(dp,-1);
    cout<<totalWays(0,1);
    return 0;
}