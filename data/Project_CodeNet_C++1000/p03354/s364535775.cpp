#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n) {
        REP(i,n) par[i] = i;
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
        return root(x) == root(y);
    }
};


int main(void)
{
    IOS
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    UnionFind uf(n);
    REP(i,n) {
        cin >> v[i];
        v[i]--;
    }
    REP(i,m) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        uf.unite(a,b);
    }

    int ans = 0;
    REP(i,n) {
        if (uf.same(i,v[i])) ans++;
    }

    cout << ans << '\n';

    return 0;
}