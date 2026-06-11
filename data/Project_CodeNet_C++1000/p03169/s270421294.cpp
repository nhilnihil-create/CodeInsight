#include <bits/stdc++.h>
using namespace std;
#define ll long
#define ld long double
ld dp[301][301][301];
ll n;
ld solve(ll x,ll y,ll z){
  if(x<0||y<0||z<0)return 0;
  if(x==0&&y==0&&z==0)return 0;
  if(dp[x][y][z]>=0)return dp[x][y][z];
  return dp[x][y][z]=(ld)((n + x * solve(x-1,y,z) + y * solve(x+1,y-1,z) + z*solve(x,y+1,z-1))/(ld)(x+y+z));
}

int main(){
  ll i,j,x,y,z;
  cin>>n;
  x=y=z=0;
  for(i=0;i<n;i++){
    cin>>j; x+=(j==1); y+=(j==2); z+=(j==3);
  }
  memset(dp,-1.0,sizeof(dp));
  cout<<fixed<<setprecision(12)<<solve(x,y,z);
}