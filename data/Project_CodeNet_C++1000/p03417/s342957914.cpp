#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define endl "\n"
using ll=long long;
using ld=long double;
using namespace std;
const ll mod= 1e9+7;
const ll INF = 1LL<<40;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int main(){
  ll n,k,ans=0;
  cin>>n>>k;
  ll x=max(n,k);
  if(n*k==1)cout<<1;
  else if(n==1||k==1)cout<<x-2;
  else cout<<(n-2)*(k-2);
}
