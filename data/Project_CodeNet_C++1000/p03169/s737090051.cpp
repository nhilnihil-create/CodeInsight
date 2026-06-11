#include<bits/stdc++.h>
using namespace std;
int n;
double dp[301][301][301];
double solve(int x , int  y ,int  z)
{ 
   if(x == 0 && y == 0 && z == 0)
    return 0;

   if(x<0 || y<0 || z<0)
    return 0;

   if(dp[x][y][z]> -1.0)
     return dp[x][y][z];

   double cal =  (n + x*solve(x-1,y,z)+y*solve(x+1,y-1,z)+z*solve(x,y+1,z-1))/(x+y+z);

   return dp[x][y][z] = cal;
}

int main(void)
{
  cin>>n;int k;
  int x,y,z;x = y = z = 0;
  for(int  i = 0;i<n;i++)
  {
    cin>>k;
    if(k==1)
      x++;
    if(k == 2)
      y++;
    if(k == 3)
      z++;
  }
   memset(dp , -1 ,sizeof dp);
    cout<<fixed<<setprecision(10)<<solve(x,y,z)<<endl;

}