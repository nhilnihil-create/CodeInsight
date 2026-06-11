#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x,y;
    cin>>x>>y;
    ll dp[x.size()+1][y.size()+1];
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=x.size();i++)
    {
     for(ll j=1;j<=y.size();j++)
     {
      if(x[i-1]==y[j-1])
        dp[i][j]=dp[i-1][j-1]+1;
      else 
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
     }
    }
   string ans="";
  ll i=x.size(),j=y.size();
  while(i>=1&&j>=1)
  {
    if(x[i-1]==y[j-1])
    {ans.insert(ans.begin(),y[j-1]);i--;j--;}
    else if (dp[i-1][j] > dp[i][j-1]) 
         i--; 
      else
         j--; 
   }
   cout<<ans;
    return 0;
}
