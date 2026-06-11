#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[3001][3001];
string s,s2;
int fun(int idx,int idx2)
{
    if(idx==s.size()||idx2==s2.size())
        return dp[idx][idx2]=0;
    int &ret=dp[idx][idx2];
    if(~ret)
        return ret;
    if(s[idx]==s2[idx2])
        return ret=1+fun(idx+1,idx2+1);
    return ret=max(fun(idx+1,idx2),fun(idx,idx2+1));
}
signed main()
{
    memset(dp,-1,sizeof dp);
   cin>>s>>s2;
   int idx=0,idx2=0;
   fun(0,0);
   string ans="";
   while(idx!=s.size()&&idx2!=s2.size())
   {

       if(s[idx]==s2[idx2])
       {
           ans+=s[idx];
           idx++;
           idx2++;
           continue;
       }
         if(dp[idx][idx2+1]<=dp[idx+1][idx2])
         {
             idx++;
         }
         else idx2++;

   }
   cout<<ans<<endl;
}
