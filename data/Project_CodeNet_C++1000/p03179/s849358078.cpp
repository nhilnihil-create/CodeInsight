#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int mod=1e9+7;
/*long mem[3005][3005];
bool vis[3005];

long rec(string s, int n, int id, int num)
{
  if(id>=n)
    return 1;
  if(num!=-1&&mem[id][num]!=-1)
    return mem[id][num];
  long ans=0;
  if(id==0)
  {
    if(s[id]=='<')
    {
      for(int i=1;i<n;i++)
      {
      	if(vis[i])
      	  continue;
      	vis[i]=true;
        ans+=rec(s,n,id+1,i);
        ans%=mod;
        vis[i]=false;
      }
    }
    else
    {
      for(int i=2;i<=n;i++)
      {
        if(vis[i])
      	  continue;
      	vis[i]=true;
        ans+=rec(s,n,id+1,i);
        ans%=mod;
        vis[i]=false;
      }
    }
  }
  else if(s[id-1]=='<')
  {
    for(int i=num+1;i<=n;i++)
    {
      if(vis[i])
     	continue;
      vis[i]=true;
      ans+=rec(s,n,id+1,i);
      ans%=mod;
      vis[i]=false;
    }
  }
  else
  {
    for(int i=1;i<num;i++)
    {
      if(vis[i])
      	continue;
      vis[i]=true;
      ans+=rec(s,n,id+1,i);
      ans%=mod;
      vis[i]=false;
    }
  }
  //cout<<id<<' '<<num<<' '<<ans<<endl;
  mem[id][num]=ans;
  return ans;
  
}*/

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  /*memset(mem,-1,sizeof(mem));
  memset(vis,0,sizeof(vis));
  
  cout<<rec(s,n,0,-1);*/
  
  
  long dp[n+1][n+1]={{0}};
  long prefix[n+1][n+1]={{0}};
  dp[1][1]=1;
  for(int len=2;len<=n;len++)
  {
    for(int i=1;i<=len-1;i++)
      prefix[len-1][i]=(prefix[len-1][i-1]+dp[len-1][i])%mod;
    for(int j=1;j<=len;j++)
    {
      int l,r;
      if(s[len-2]=='<')
        l=1,r=j-1;
      else
        l=j,r=len-1;
      if(l<=r)
      {
        dp[len][j]+=(prefix[len-1][r]-prefix[len-1][l-1]+mod)%mod;
        dp[len][j]%=mod;
      }
      /*
      for(int k=1;k<=len-1;k++)
      {
      	int reala=a;
        if(a>=b)
          reala++;
        if(reala<j != s[len-2]=='<')
          continue;
        dp[len][j]+=dp[len-1][a];
      }
      */
    }
  }
  long ans=0;
  for(int i=1;i<=n;i++)
  {
    ans+=dp[n][i]%mod;
    ans%=mod;
  }
  cout<<ans;
  

}