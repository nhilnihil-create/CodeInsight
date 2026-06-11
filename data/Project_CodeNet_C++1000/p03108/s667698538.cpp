#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;

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
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    ll n,m;
    cin>>n>>m;
    vector<pair<int,int>> vp;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        vp.push_back(make_pair(a,b));
    }
    reverse(all(vp));
    ll now=((n-1)*n)/2;
    UnionFind uf(n+1);
    vll ans;
    rep(i,m){
        ans.push_back(now);
        int x=vp[i].first;
        int y=vp[i].second;
        if (uf.issame(x,y))continue;
        else{
            ll xs=uf.size(x);
            ll ys=uf.size(y);
            now-=xs*ys;
            uf.merge(x,y);
        }
    }
    rep(i,m){
        cout<<ans[m-1-i]<<endl;
    }
    

    return 0;
}