#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;

struct UnionFind {
    vector<int> par;
    vector<int> siz;
    UnionFind(int N) : par(N), siz(N, 1) {
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
        if (siz[rx] < siz[ry]) swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }

    bool issame(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    ll n,m;
    cin >> n >> m;
    UnionFind tree(n);
    vector<int> a(m),b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        --a[i]; --b[i];
    }
    ll now=n*(n-1)/2;
    vector<ll> ans(m);
    invrep(i,m) {
        ans[i]=now;
        if (!tree.issame(a[i],b[i])) {
            ll ta=tree.size(a[i]),tb=tree.size(b[i]);
            now-=ta*tb;
            tree.unite(a[i],b[i]);
        }
    }
    rep(i,m) cout << ans[i] << endl;

    return 0;   
}
