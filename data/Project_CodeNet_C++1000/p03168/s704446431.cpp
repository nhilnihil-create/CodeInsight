#include<bits/stdc++.h>
using namespace std;
double dp[3001][3001];
double solve(vector<double>& arr,int N,int i,int x)
{
  
  	if(x==0)
    {
      return 1;
    }
  if(i==0)
    return 0;
  if(dp[i][x]> -0.9)
    return dp[i][x];
  
  
    return dp[i][x]=arr[i]*solve(arr,N,i-1,x-1) + (1-arr[i])*solve(arr,N,i-1,x);
}

int main()
{
  int N;
  cin>>N;
  vector<double> arr(N+1);
  for(int i=1;i<=N;i++)
    cin>>arr[i];
  memset(dp,-1,sizeof dp);
  int x=(N+1)/2;
  cout<<fixed<<setprecision(10)<<solve(arr,N,N,x);
  
  return 0;
}