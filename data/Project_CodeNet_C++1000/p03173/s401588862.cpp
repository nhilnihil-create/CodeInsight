  #include <bits/stdc++.h>
 
  using namespace std;
  long long MOD=1000000007;
  #define IOS() ios_base::sync_with_stdio(0); cin.tie(0);
  typedef long long ll;
  #define pb push_back
  typedef pair<ll,ll> pi;
  ll dp[401][401];
  ll sum[401][401];
  ll a[500];
  int n;

ll find (int l , int r )
{ 
    ll ans=LONG_LONG_MAX;
    // cout<<"ans is "<<ans<<endl;
    if(l==r)
      return dp[l][r]=0ll;

    else if(dp[l][r]!=-1)
      return dp[l][r];

    else
    {
      for(int i=l;i<r;i++)
      {
        ans=std::min(ans, sum[l][r] + find(l,i) + find(i+1,r));
      }
      return dp[l][r]=ans;
    }
}
void preprocess()
{
    for(int i=1;i<=n;i++)
    {
      sum[i][i]=a[i];

      for(int j=i+1;j<=n;j++)
      {
        sum[i][j]=sum[i][j-1]+a[j];
      }
    }
}

int main()
{
  IOS();
  cin>>n;
  
  memset(dp,-1ll ,sizeof dp);

  for (int i = 1; i <=n; ++i)
  {
      cin>>a[i];
      
  }

  preprocess();

  ll ans=find(1,n);
  cout<<ans<<endl;

  return 0;
}