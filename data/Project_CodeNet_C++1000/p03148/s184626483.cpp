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

vector<vector<ll>> f(110000);
vector<ll> subsushi;
ll ksushi[110000];
main(){
  ll n,k,t,d,ks=0,kkind=0;
  cin>>n>>k;
  rep(i,0,n){cin>>t>>d;f[t-1].pb(d);}
  for(auto &i:f){
    sort(i.rbegin(),i.rend());
    if(i.empty())i.pb(0);
    else kkind++;
  }
  sort(f.begin(),f.end(),[&](vector<ll> a, vector<ll> b) {return a[0] > b[0];});
  kkind=min(kkind,k);
  rep(i,0,kkind){ks+=f[i][0];ksushi[i+1]=ks;}
  rep(i,kkind,f.size())subsushi.pb(f[i][0]);
  ks+=kkind*kkind;
  rep(i,0,f.size()){
    rep(j,1,f[i].size()){
      subsushi.pb(f[i][j]);
    }
  }
 
  sort(subsushi.rbegin(),subsushi.rend());
  irep(i,kkind,1){
    ll tmp=ksushi[i];
    rep(j,0,min(k-i,n-kkind))tmp+=subsushi[j];
    tmp+=i*i;
    if(ks<tmp)ks=tmp;
  }
  cout<<ks;
}
