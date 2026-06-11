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
vector<vector<ll>> dp(21,vector<ll>(1<<21,-1));
bool a[21][21];
ll func(ll m,ll n,ll l)
{ 
  ll ans=0;
  if(dp[n-1][m]!=-1) return dp[n-1][m];

  if(n==1)
  {
    fr(j,0,l)
      if(a[0][j] && (m & 1<<j))
        ans+=1;
    return dp[n-1][m]=ans;
  }

  fr(j,0,l)
    if(a[n-1][j] && (m & 1<<j))
    {
      ans+=func(m^(1<<j),n-1,l);
      ans%=Mo;
    }

  return dp[n-1][m]=ans;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n; cin>>n;
  fr(i,0,n)
    fr(j,0,n)
      cin>>a[i][j];

  cout<<func((1<<n)-1,n,n);
}
