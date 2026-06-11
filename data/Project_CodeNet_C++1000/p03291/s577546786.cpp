#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;


int main()
{
   ll i,j,k,n,m;
   string s; cin>>s;
   n=s.length();
   ll dp[n+1][4]={0};
   dp[0][0]=1;
   for(i=1;i<=n;i++)
   {
       for(j=0;j<4;j++)
       {
           if(s[i-1]=='?') dp[i][j]=(dp[i][j]+3*dp[i-1][j])%mod;
           else dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
       }
       if(s[i-1]=='A' || s[i-1]=='?') dp[i][1]=(dp[i-1][0]+dp[i][1])%mod;
       if(s[i-1]=='B' || s[i-1]=='?') dp[i][2]=(dp[i-1][1]+dp[i][2])%mod;
       if(s[i-1]=='C' || s[i-1]=='?') dp[i][3]=(dp[i-1][2]+dp[i][3])%mod;
   }
   cout<<dp[n][3]<<endl;
   return 0;
}
