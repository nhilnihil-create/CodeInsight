#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int dp[k+1][2];
  memset(dp,0,sizeof(dp));

  for(int i=0;i<=k;i++)
  {
    for(int j=0;j<2;j++)
    {
      for(int m=0;m<n;m++)
      {
        if(i-arr[m]>=0)
        dp[i][j] |= !dp[i-arr[m]][1^j];
      }
    }
  }
  cout << (dp[k][0] ? "First" : "Second") << endl;
  return 0;
}