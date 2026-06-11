#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using T = tuple<ll,ll,ll>;
using vec = vector<ll>;
using vecp = vector<P>;
using mat = vector<vec>;
using matp = vector<vecp>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

//重み付きUnionFind
vector<ll> par(1e6);
vector<ll> ran(1e6);
vector<ll> diff_weight(1e6);
void init(ll n){
  rep(i,n){
    par.at(i)=i;
    ran.at(i)=0;
    diff_weight.at(i)=0;
  }
}
ll find(ll x){
  if(par.at(x)==x){
    return x;
  }else{
    ll f=find(par.at(x));
    diff_weight.at(x)+=diff_weight.at(par.at(x)); // 累積和をとる
    return par.at(x)=f;
  }
}
ll weight(ll x) {
  find(x); // 経路圧縮
  return diff_weight.at(x);
}
void unite(ll x,ll y,ll w){
  w+=weight(x);
  w-=weight(y);
  x=find(x);
  y=find(y);
  if(x==y) return;
  if(ran.at(x)<ran.at(y)){
    par.at(x)=y;
    diff_weight.at(x)=-w;
  }else{
    par.at(y)=x;
    diff_weight.at(y)=w;
    if(ran.at(x)==ran.at(y)) ran.at(x)++;
  }
}

int main(){
  ll N,M;
  cin >> N >> M;
  init(N);
  rep(i,M){
    ll L,R,D;
    cin >> L >> R >> D;
    L--;
    R--;
    if(find(L)==find(R)){
      if(weight(R)-weight(L)!=D){
        cout << "No" << endl;
        return 0;
      }
    }else{
      unite(L,R,D);
    }
  }
  cout << "Yes" << endl;
}
          