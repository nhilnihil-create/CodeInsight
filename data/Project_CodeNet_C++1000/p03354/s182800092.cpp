#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;
 

struct UnionFind {
    vector<int> par;
    UnionFind(int N) : par(N) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i,n) {
        cin >> p[i];
        --p[i];
    }
    UnionFind tree(n);
    rep(i,m) {
        int x,y;
        cin >> x >> y;
        tree.unite(x-1,y-1);
    }
    int ans=0;
    rep(i,n) {
        if (tree.root(i)==tree.root(p[i])) ++ans;
    }
    cout << ans << endl; 
}