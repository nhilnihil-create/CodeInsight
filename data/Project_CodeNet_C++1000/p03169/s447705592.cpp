#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
double dp[301][301][301];
int tot;
double solve(int x,int y,int z)
{
  if(x==0&&y==0&&z==0)
  return 0;
  if(dp[x][y][z]>-0.9)
  return dp[x][y][z];
  double ans=(tot+(x>=1?(x*solve(x-1,y,z)):0)+(y>=1?(y*solve(x+1,y-1,z)):0)+(z>=1?(z*solve(x,y+1,z-1)):0));
  return dp[x][y][z]=(ans/(x+y+z));
} 
int main()
{
  memset(dp,-1.0,sizeof(dp));
  int n,one=0,two=0,three=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
     int x;
     cin>>x;
     x==1?one++:((x==2)?two++:three++);
  }
  tot=one+two+three;
  double ans=solve(one,two,three);
  cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;
}