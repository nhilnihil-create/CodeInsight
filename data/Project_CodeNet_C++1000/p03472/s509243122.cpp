#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>(b);--i)
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
  ll n,h,hp=0,ans=0;cin>>n>>h;
  vp a(2*n);
  rep(i,0,n){
    cin>>a[2*i].first>>a[i*2+1].first;
    a[2*i].second=MOD;
    a[i*2+1].second=1;
  }
  sort(a.begin(),a.end());reverse(a.begin(),a.end());
  ll i=0;
  while(hp<h&&a[i].second==1){
    hp+=a[i].first*a[i].second;
    i++;
    ans++;
  }
  if(hp<h){
    ll x=(h-hp)/a[i].first;
    ans+=x;
  if((h-hp)%a[i].first!=0)ans++;
  }
  cout<<ans<<endl;
}


