#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()
using P = pair<int,int>;

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};


int main(){
  ll N,M;cin>>N>>M;
  vll ans;
  vector<pair<int,int>> vp;
  ll tmp = N*(N-1)/2;
  rep(i,M){
    int a,b;cin>>a>>b;a--,b--;
    vp.push_back(make_pair(a,b));
  }
  UnionFind tree(N);
  for(int i=M-1;i>=0;i--){
    ans.push_back(tmp);
    if(tree.issame(vp[i].first,vp[i].second)) continue;
    ll a = tree.size(vp[i].first);
    ll b = tree.size(vp[i].second);
    tmp -= a * b;
    tree.merge(vp[i].first,vp[i].second);
  }
  reverse(all(ans));
  rep(i,ans.size()) cout << ans[i] << endl;
}