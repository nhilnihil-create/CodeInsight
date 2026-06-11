#include <bits/stdc++.h>
using namespace std;
int a[301];
double dp[301][301][301];
int n;
double f(int x,int y,int z)
{
  if(x==0 && y==0 && z==0) return 0.0;
  if(x<0 || y<0 || z<0) return 0.0;
  if(dp[x][y][z] != -1) return dp[x][y][z];
  double ans =  (double)(n+x*f(x-1,y,z) + y*f(x+1,y-1,z) + z*f(x,y+1,z-1))/(x+y+z);
  dp[x][y][z] = ans;
  return ans;
}



int main() {
  cin>>n;
  for(int i=0;i<301;i++)
  {
    for(int j=0;j<301;j++)
    {
      for(int k=0;k<301;k++)
      {
        dp[i][j][k] = -1;
      }
    }
  }
  int x=0,y=0,z=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    if(a[i] == 1) x++;
    else if(a[i] == 2) y++;
    else if(a[i] == 3) z++;
  } 
  cout<<fixed<<setprecision(10)<<f(x,y,z)<<endl;
  return 0;
}