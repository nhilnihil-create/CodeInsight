#include <bits/stdc++.h>
#include <vector>
#include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9+5;
const int mod = 1e9+7;
struct UnionFind {
vector<int> d;
UnionFind(int n): d(n, -1) {}
int root(int x) {
if(d[x] < 0) return x;
return d[x] = root(d[x]);
}
bool unite(int x, int y) {
x = root(x); y = root(y);
if(x == y) return false;
if(d[x] > d[y]) swap(x, y);
d[x] += d[y];
d[y] = x;
return true;
}
bool same(int x, int y) {return (root(x) == root(y));}
int size(int x) {return -d[root(x)];}
};

signed main(){
    int n,m;
    cin >> n>> m;
    vector<pair<int,int> > p;
    vector<int> ans(m);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        p.push_back(make_pair(a, b));
    }
    ans[m-1]=n*(n-1)/2;
    UnionFind uf(n);
    RFOR(i,m-1,1) {
        pair<int,int> pp = p[i];
        if(uf.same(pp.first,pp.second)) {
            ans[i-1]=ans[i];
        }else{
            ans[i-1]=ans[i]-(uf.size(pp.first)*uf.size(pp.second));
        }
        uf.unite(pp.first, pp.second);
    }
    rep(i,m) {
        cout << ans[i] << endl;
    }
    return 0;

}
