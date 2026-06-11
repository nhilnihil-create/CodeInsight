#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mod 1000000007
const int N=101;
const int K=100001;
ll dp[N][K];


int main()
{
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];

  dp[0][0]=1;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=k;j++)
    {
      dp[i][j]+=dp[i-1][j];
      dp[i][j]=dp[i][j]%mod;
      if(j!=0)
      {
        dp[i][j]=dp[i][j]+dp[i][j-1];
        dp[i][j]=dp[i][j]%mod;
      }

      if(j-a[i-1]-1>=0)
      {
        dp[i][j]+=mod;
        dp[i][j]-=dp[i-1][j-a[i-1]-1];
        dp[i][j]=dp[i][j]%mod;
      }
    }
  }
  cout<<dp[n][k]<<endl;
}
