#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;++i)
#define ocut cout
#define ouct cout
#define itn int

struct Union{
  vector<ll> par;
  Union(ll a){
  par=vector<ll>(a,-1);
  }
  ll find(ll a){
    if(par[a]<0){
      return a;
    }
    else{
      return par[a]=find(par[a]);
    }
  }
  bool same(ll a,ll b){
    return (find(a)==find(b));
  }
  ll size(ll a){
    return -par[find(a)];
  }
  void unite(ll a,ll b){
    ll c=find(a),d=find(b);
    if(c==d)
      return;
    if(size(c)<size(d)){
      swap(c,d);
    }
    par[c]+=par[d];
    par[d]=c;
  }
};
ll Nagaemon1;
void swap(ll i,ll j){
  Nagaemon1=i;
  i=j;
  j=Nagaemon1;
}
int main(){
  ll n,m;
  cin >> n >> m;
  cout << (1900*m+100*(n-m))*pow(2,m) << endl;
}