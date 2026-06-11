#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<ll>>;

struct UnionFind {
  vector<ll> par;

  UnionFind(ll n) : par(n,-1){}
  void init(ll n) { par.assign(n, -1); }

  ll root(ll x){//xを根とする連結成分
    if(par[x]<0) return x;
    else return par[x] = root(par[x]);
  }

  bool same(ll x, ll y){
    return root(x) == root(y);
  }

  bool merge(ll x, ll y){
    x = root(x);
    y = root(y);
    if(x==y) return false;
    if(par[x] > par[y]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  ll size(ll x){
    return -par[root(x)];
  }
};

int main(){
    ll N,M; cin>>N>>M;
    vector<pair<ll,ll>> B;
    rep(i,M){
        ll a,b; cin>>a>>b;
        B.push_back({a-1,b-1});
    }
    reverse(B.begin(),B.end());
    vector<ll> res;
    ll now = N*(N-1)/2;
    UnionFind T(N);
    rep(i,M){
        res.push_back(now);
        ll a = B.at(i).first,b = B.at(i).second;
        if(T.same(a,b)) continue;
        ll n1 = T.size(a);
        ll n2 = T.size(b);
        now -= n1*n2;
        T.merge(a,b);
        
    }
    reverse(res.begin(),res.end());
    rep(i,res.size())cout<<res.at(i)<<endl;
}
