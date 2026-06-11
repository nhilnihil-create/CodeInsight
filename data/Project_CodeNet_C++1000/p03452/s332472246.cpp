#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;

template<class T> struct Weighted_UnionFind{
  vector<ll> par;
  vector<ll> rank;
  vector<T> diff_weight;

  Weighted_UnionFind(ll n){
    init(n);
  }

  void init(ll n){
    par.resize(n);
    rank.resize(n);
    diff_weight.resize(n);
    REP(i,n){
      par[i] = i;
      rank[i] = 0;
      diff_weight[i] = 0;
    }
  }

  ll find(ll x){
    if(par[x]==x){
      return x;
    }else{
      ll r = find(par[x]);
      diff_weight[x]+=diff_weight[par[x]];
      return par[x] = r;
    }
  }

  T weight(ll x){
    find(x);
    return diff_weight[x];
  }

  bool same(ll x, ll y){
    return find(x)==find(y);
  }

  void unite(ll x, ll y, T w){
    w += weight(x);
    w -= weight(y);
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(rank[x]<rank[y]) swap(x,y), w = -w;
    if(rank[x]==rank[y]) rank[x]++;
    par[y] = x;
    diff_weight[y] = w;
  }

  T diff(ll x, ll y){
    return weight(y)-weight(x);
  }
};

int main(){
  ll n,m;
  cin >> n >> m;
  Weighted_UnionFind<ll> uf(n);
  REP(i,m){
    ll l,r,d;
    cin >> l >> r >> d;
    l--, r--;
    if(uf.same(l,r)){
      ll diff = uf.diff(l,r);
      if(diff!=d){
        cout << "No" << endl;
        return 0;
      }
    }else{
      uf.unite(l,r,d);
    }
  }
  cout << "Yes" << endl;
  return 0;
}
