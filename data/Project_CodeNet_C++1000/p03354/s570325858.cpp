#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
using namespace std;

struct UnionFind{
    vector<int> par;
    UnionFind(int n) : par(n) {
        rep(i, n) par[i] = i;
    }
    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx != ry)par[rx] = ry;
    }
    bool same(int x, int  y){
        return root(x) == root(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n)cin >> p.at(i);
    UnionFind tree(n);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        tree.unite(x-1, y-1);
    }
    int ans = 0;
    rep(i, n){
        if(tree.same(i,p.at(i)-1))ans++;
    }
    cout << ans << endl;
}