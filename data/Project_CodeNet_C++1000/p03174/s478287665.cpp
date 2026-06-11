#include<bits/stdc++.h>
using namespace std;
int dp[22][3000001];
int vis[22][3000001];
int a[22][22];
int n;
int cal(int pos,int mask)
{
  
  if(mask+1==(1<<n))
    return 1;
  if(pos==n)
    return 0;
  if(vis[pos][mask]==0)
    vis[pos][mask]=1;
    else
    return dp[pos][mask];
  int ways=0;
  for(int i=0;i<n;i++)
  {
    if(a[pos][i]==1&&(mask&1<<i)==0)
    {
      ways+=(cal(pos+1,mask|1<<i)%1000000007);
      ways%=1000000007;
    }  
  }
  dp[pos][mask]=ways;
  return dp[pos][mask];
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin>>a[i][j];
      }
    }
  	int res=cal(0,0);
  	cout<<res<<"\n";
}