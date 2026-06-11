                    //S.G.N.//
#include <bits/stdc++.h>
using namespace std;
typedef vector< long long > vi;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define endl "\n"
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fr(n) for(ll i=0;i<n;i++)
#define tr(a) for(auto it=a.begin();it!=a.end();it++)
#define N 998244353445 
#define PI 3.1415926535897932384
#define F first
#define S second
#define mp make_pair
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007


void solve()
{
 ll n;
 cin>>n;
 ll a[n][n];
 fr(n){
 rep(j,0,n)
 {
  cin>>a[i][j];
 }
}
ll dp[2][1<<n];
fr(2)
{
  rep(j,0,1<<n)
  {
    dp[i][j]=0;
  }
}

dp[0][0]=1;
rep(i,1,n+1)
{
rep(j,0,1<<n)
{
  dp[i%2][j]=0;
  if(__builtin_popcount(j) != i)
    continue;
  rep(k,0,n)
  {
    if(j&1<<k&&a[i-1][k])
    {
      
      dp[i%2][j]+=dp[(i-1)%2][j^1<<k];
      dp[i%2][j]=dp[i%2][j]%mod;
    }
  }
  
}

}

cout<<dp[n%2][(1<<n)-1];
}
int main()
{
  
  #ifndef ONLINE_JUDGE
     * freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
  FAST
  ll test;
test=1;
  //cin>>test;
  while(test--)
  {
    solve();
  }
  return 0;
}
