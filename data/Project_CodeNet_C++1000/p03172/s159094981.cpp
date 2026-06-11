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
ll n,k;
cin>>n>>k;
ll a[n];
fr(n)
{
  cin>>a[i];
} 
ll dp2[n+1];
dp2[n]=0;
for(ll i=n-1;i>=1;i--)
dp2[i]=dp2[i+1]+a[i];
ll dp[n+1][k+1];
fr(k+1)
dp[0][i]=0;
fr(n+1)
dp[i][0]=1;
fr(n+1)
{
 if(i==0)
 continue; 
ll prev=0;
ll c=0;
rep(j,max(0ll,k-dp2[i]-a[i-1]),k+1)
{
  c++;
  prev+=dp[i-1][j];
  prev=prev%mod;
  if(c>=a[i-1]+2)
  {
    prev-=dp[i-1][j-a[i-1]-1];
    prev=(prev+mod)%mod;
  }
  //cout<<j<<" "<<c<<" "<<prev<<endl;
  if(j>=k-dp2[i]){
    dp[i][j]=prev;
    //cout<<dp[i][j]<<endl;
  }
    
    

}
//cout<<endl;
}
cout<<dp[n][k];
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
