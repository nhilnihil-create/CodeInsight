#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct UnionFind
{
    vector<ll> par;
    vector<ll> rank;
    vector<ll> sz;
    UnionFind(ll n) : par(n), rank(n), sz(n)
    {
        for(ll i = 0; i < n; i++)
        {
            par[i] = i;
            rank[i] = 0;
            sz[i] = 1;
        }
    }
    ll root(ll x)
    {
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }
    void unite(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(rank[x] < rank[y])
        {
            par[x] = y;
            sz[y] += sz[x];
        }
        else
        {
            par[y] = x;
            sz[x] += sz[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }
    ll size(ll x)
    {
        x = root(x);
        return sz[x];
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    for(int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    UnionFind tree(n);
    vector<ll> ans(m);
    ll con = n * (n-1) / 2;
    for(int i = m-1; i >= 0; i--)
    {
        ans[i] = con;
        if(tree.same(a[i], b[i])) continue;
        ll asize = tree.size(a[i]);
        ll bsize = tree.size(b[i]);
        tree.unite(a[i], b[i]);
        ll size = tree.size(a[i]);
        con = con - size * (size-1) / 2 + asize * (asize-1) / 2 + bsize * (bsize-1) / 2;
    }
    for(int i = 0; i < m; i++)
    {
        cout << ans[i] << endl;
    }
}
