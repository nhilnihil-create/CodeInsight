#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
 
int main (void)
{
  int n,m;
  cin>>n>>m;
  if(n>m){cout<<0<<endl;return 0;}
  int i,j,x[100000],dp[100000],ans=0;//dp草
  for(i=0;i<m;i++)
  {
    cin>>x[i];
  }
  sort(x,x+m);
  for(i=0;i<m-1;i++)
  {
    dp[i]=x[i+1]-x[i];
  }
 
  
  sort(dp,dp+m-1);
  
 
  
  for(i=0;i<m-n;i++)
  {
    ans+=dp[i];
 
  }
  cout<<ans<<endl;
}