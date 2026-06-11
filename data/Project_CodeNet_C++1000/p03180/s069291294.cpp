/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,a[20][20],val[70000],dp[70000];

LL dfs(int mask)
{
  if(dp[mask]!=-1e18) return dp[mask];
  int num=__builtin_popcount(mask);
  if(num==0) return dp[mask]=0;
  rep(i,1<<num)
  {
    int tmp=0,now=0;
    rep(j,n)
    {
      if((mask&(1<<j))>0)
      {
        tmp|=((i>>now)&1)<<j;
        now++;
      }
    }
		if(tmp==0) continue;
    dp[mask]=max(dp[mask],val[tmp]+dfs(mask-tmp));
  }
  return dp[mask];
}

int main()
{
  cin>>n;
  rep(i,n) rep(j,n) cin>>a[i][j];
  rep(i,1<<n) rep(j,n) for(int k=j+1;k<n;k++) if((i&(1<<j))>0&&(i&(1<<k))>0) val[i]+=a[j][k];
  rep(i,69995) dp[i]=-1e18;
  cout<<dfs((1<<n)-1)<<endl;
  return 0;
}