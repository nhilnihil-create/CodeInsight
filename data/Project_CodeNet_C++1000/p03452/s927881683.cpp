//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};
int main(){
  ll n,m;cin>>n>>m;
  UnionFind<ll>uf(n);
  rep(i,m){
    ll l,r,d;cin>>l>>r>>d;
    l--;r--;
    if(uf.issame(l,r)){
      ll diff=uf.diff(l,r);
      if(diff!=d){
        cout<<"No"<<endl;
        return 0;
      }
    }
    else uf.merge(l,r,d);
  }
  cout<<"Yes"<<endl;
}
