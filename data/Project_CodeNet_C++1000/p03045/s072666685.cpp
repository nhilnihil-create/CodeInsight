#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

struct UnionFind
{
    vector<int> par;

    UnionFind(int N) : par(N)
    {
        for (int i = 0; i < N; i++)
            par[i] = i;
    }

    int root(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {                     
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        par[rx] = ry;
    }

    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    UnionFind tree(n);

    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z, --x, --y;
        tree.unite(x, y);
    }

    int ans = 0;
    rep(i, n) ans += (i == tree.root(i));

    cout << ans << endl;
}