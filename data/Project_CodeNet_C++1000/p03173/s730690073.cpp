#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<long long>A(n),pre(n);
  for(int i=0;i<n;i++)
  {
  	cin>>A[i];
  	pre[i]=i==0?A[i]:pre[i-1]+A[i];
  }
  vector<vector<long long>> dp(n,vector<long long>(n,pow(10,18)));
  for(int i=n-1;i>=0;i--)
  {
    for(int j=i;j<n;j++)
    {
      if(i==j)dp[i][j]=0;
      else if(j==i+1)dp[i][j]=pre[j]-pre[i]+A[i];
      else
      {
        for(int k=i;k<j;k++)
          dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+pre[j]-pre[i]+A[i]);
      }
    }
  }
  cout<<dp[0][n-1];
}
  