
  #include <bits/stdc++.h>
  using namespace std;
  long long MOD=1000000007;
  #define IOS() ios_base::sync_with_stdio(0); cin.tie(0);
  typedef long long ll;
  #define pb push_back
  typedef pair<ll,ll> pi;
  

int main()
{
  IOS();
  int n;
  int k;
  cin>>n>>k;
  int a[n+1];
  for (int i = 1; i <=n; ++i)
  {
      cin>>a[i];
  }

  ll dp[n+1][k+1]={0ll};

  for(int j=0;j<=k;j++)
  {
    if(j<=a[1])
      dp[1][j]=1;
    else
      dp[1][j]=0;
  }


  for(int i=2;i<=n;i++)
  {

    for(int j=0;j<=k;j++)
    {

      if(j==0)
        dp[i][j]=dp[i-1][j];

      else{
        dp[i][j]=( MOD + dp[i][j-1]+dp[i-1][j] - ((j-a[i]-1>=0)? dp[i-1][j-a[i]-1] : 0))%MOD;
       
      }
    }

  }

  cout<<dp[n][k]<<endl;

  return 0;
}