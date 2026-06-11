#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD=1e9+7;
#define endl '\n'
#define F first
#define S second
#define pb push_back
const double PI = 3.141592653589793238460;
  void c_p_c()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
    #endif
}
mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
long long int binpow(long long int a, long long int b) {
    long long int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


void solve()
{
  int n,m;cin>>n>>m;
  char s[n+1][m+1];
  int dp[n+1][m+1];
  memset(dp,0,sizeof(dp));
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>s[i][j];
    }
  }
  int flag=0,flag2=0;
  for(int i=1;i<=n;i++)
  {
    if(s[i][1]=='#')
    {
      flag=1;

    
    }
    if(flag==1)
      dp[i][1]=0;
    else
      dp[i][1]=1;


  }
  for(int i=1;i<=m;i++)
  {
    if(s[1][i]=='#')
    {
      flag2=1;
      
    }
    if(flag2==1)
      dp[1][i]=0;
    else
      dp[1][i]=1;
    

  }

 



    for(int i=2;i<=n;i++)
  {
    for(int j=2;j<=m;j++)
    {
      if(s[i][j]=='.')
        dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
      else
        dp[i][j]=0;
      
    }
  }
  cout<<dp[n][m]%MOD;


  

}



int  main()
{
  c_p_c();
  int t=1;
  while(t--)
  {
    solve();
  }


 

  return 0;

}