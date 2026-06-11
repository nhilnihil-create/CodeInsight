#include<bits/stdc++.h>
#define Mx 1000000000005 
#define ll long long  
#define pi 3.141592653
#define vi vector<ll>
#define Mo 1000000007
#define mp make_pair
#define M map<ll,ll>
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define vii vector<pair<ll,ll> > 
#define fi first
#define se second
#define pb push_back
#define ld long double
#define fill(a,x) memset(a,x,sizeof(a))
using namespace std;
bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
  return a.second<b.second;
}
/*vi b=v;
   sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  ll t; cin>>t; fr(f,0,t){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 */
ll func(ll a[],ll n,ll k)
{
  if(k==0) return 1;
  if(k<0 || n==0) return 0;

  ll ans=0;
  fr(i,0,a[n-1]+1)
  {
    ans+=func(a,n-1,k-i);
    ans%=Mo;
  }
  return ans;
}
int main()
{
  ll n,k,l,r; cin>>n>>k;
  ll a[n];
  fr(i,0,n)
    cin>>a[i];

  ll dp[n+1][k+1],p[n+1][k+1];
  fill(dp,0);
  fill(p,0);

  fr(i,0,n+1)
  {
    dp[i][0]=1;
    p[i][0]=1;
  }
 
  fr(j,1,k+1)
    p[0][j]+=p[0][j-1];

  fr(i,1,n+1)
  {
    fr(j,1,k+1)
    {
      r=j; l=j-a[i-1];
      dp[i][j]+=p[i-1][r];

      dp[i][j]%=Mo;

      if(l>0) dp[i][j]-=p[i-1][l-1]; 
      if(dp[i][j]<0) dp[i][j]+=Mo;

      p[i][j]=p[i][j-1]+dp[i][j];
      p[i][j]%=Mo;

    }
  }

  cout<<dp[n][k];


}