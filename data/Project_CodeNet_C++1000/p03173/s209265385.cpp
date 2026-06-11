#include<bits/stdc++.h>
using namespace std;
int a[405];
long long int dp[405][405];

int main(){
      int n;
      cin>>n;
      for(int i=0; i<n; i++)
            cin>>a[i];
      long long int sum[n];
      sum[0]=a[0];
      for(int i=1; i<n; i++)
      {
            sum[i]=sum[i-1]+a[i];
      }
      for(int i=0; i<n; i++)
      {
            for(int j=0; j<n; j++)
                  dp[i][j]=LONG_LONG_MAX;
      }
      for(int i=0; i<n; i++)
            dp[i][i]=0;

      for(int i=n-1; i>=0; i--)
      {
            for(int j=i+1; j<n; j++)
            {
                  for(int k=i; k<j; k++)
                        dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+sum[j]-((i)?sum[i-1]:0));
            }
      }
      cout<<dp[0][n-1];
}