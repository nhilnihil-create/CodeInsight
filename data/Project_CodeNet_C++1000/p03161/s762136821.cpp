
#include<bits/stdc++.h>

using namespace std;
 
int main()
{
  int n , k;
  cin>>n>>k;
  int h[n];
  for(int i=0 ; i<n ; i++)
    cin>>h[i];
  
  int dp[n+1];
  dp[0]=0;
  dp[1]=0;
  dp[2]=abs(h[0]-h[1]);
  
  for(int i=3 ; i<=n; i++)
  {
    int res=INT_MAX;
    for(int j=1 ; j<=k ; j++)
    {
      if((i-j)>=1)
      	res=min(res , dp[i-j]+abs(h[i-j-1] - h[i-1]) );
    }
    dp[i]=res;
  }
  
  cout<<dp[n];
  return 0;
}