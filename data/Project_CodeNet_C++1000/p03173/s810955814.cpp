#include<bits/stdc++.h>
//#define Mx 1000000000005 
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
const long long Mx = 1e15 + 7;
int main()
{
  ll n; cin>>n;
  ll a[n];
  fr(i,0,n)
    cin>>a[i];

  vector<vector<ll>> dp(n,vector<ll>(n,Mx));
  ll p[n];
  p[0]=a[0];
  fr(i,1,n)
    p[i]=p[i-1]+a[i];

  fr(i,0,n)
    dp[i][i]=0;

  fr(l,2,n+1)
  {
    fr(i,0,n-l+1)
    {
      ll j=i+l-1;

      if(l==2)  { dp[i][j]=a[i]+a[j]; continue; }

      fr(k,i,j)
      {
        if(i>0)
          dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[j]-p[i-1]);
        else 
          dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[j]);
      }

    }
  }

  cout<<dp[0][n-1];


}