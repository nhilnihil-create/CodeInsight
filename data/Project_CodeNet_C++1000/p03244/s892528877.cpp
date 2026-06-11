#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

int main(){
  ll n;cin>>n;
  map<ll,ll> s,t;
  rep(i,0,n){
    ll a;cin>>a;

    if(i%2){s[a]++;}
    else{t[a]++;}
  }
  ll ms=0,mt=0,ss,mt2=0,ms2=0,tt;
  for(auto u:s){
    if(ms<u.second){
      ms=u.second;
      ss=u.first;
    }
  }
  for(auto v:t){
    if(v.first==ss)continue;
    mt=max(mt,v.second);
  }
  for(auto u:t){
    if(mt2<u.second){
      mt2=u.second;
      tt=u.first;
    }
  }
  for(auto v:s){
    if(v.first==tt)continue;
    ms2=max(ms2,v.second);
  }
  cout<<min(n-ms-mt,n-ms2-mt2)<<endl;
}

