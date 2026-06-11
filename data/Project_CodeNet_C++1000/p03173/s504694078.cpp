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
 ll a[n];
 fr(n)
 cin>>a[i];
    ll dp1[n][n];
    ll dp2[n][n];
    fr(n)
    {
      rep(j,0,n)
      {
        if(i==j){
          dp1[i][j]=0;
        
        dp2[i][j]=a[i];
      }
      else{
        dp1[i][j]=10000000000000000;
        dp2[i][j]=10000000000000000;
}

      }
    }
  rep(i,1,n+1)
  {
    rep(j,0,n-i+1)
    {
      rep(k,j,j+i-1){
      if(dp1[j][j+i-1]+dp2[j][j+i-1]>dp1[j][k]+dp1[k+1][j+i-1]+2*dp2[j][k]+2*dp2[k+1][j+i-1]){
      dp2[j][j+i-1]=dp2[j][k]+dp2[k+1][j+i-1];
      dp1[j][j+i-1]=dp1[j][k]+dp1[k+1][j+i-1]+dp2[j][k]+dp2[k+1][j+i-1];
    }
    }
    //cout<<dp1[j][j+i-1]<<" "<<dp2[j][j+i-1]<<endl;
    }
  }
cout<<dp1[0][n-1];
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
