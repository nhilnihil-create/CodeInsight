#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9+7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,w; cin>>h>>w; 
    char arr[h+1][w+1]; ll dp[h+1][w+1];
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=h;i++)
    {
     for(ll j=1;j<=w;j++)
     {
      cin>>arr[i][j];
       if(arr[i][j]=='#')
       {
         dp[i][j]=-1;
       }
     }
    }
    for(ll i=1;i<=w;i++)
    {
     if(dp[1][i]==0) dp[1][i]=1;
      else break;
    }
    for(ll i=2;i<=h;i++)
    {
     if(dp[i][1]==0) dp[i][1]=1;
      else break;
    }
    for(ll i=2;i<=h;i++)
    {
     for(ll j=2;j<=w;j++)
     {
       if(dp[i][j]!=-1)
       {
         if(dp[i-1][j]>0) dp[i][j]=(dp[i][j]+dp[i-1][j])%M;
         if(dp[i][j-1]>0) dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
       }
     }
    }
    cout<<dp[h][w];
    return 0;
}
