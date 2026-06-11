#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

//けんちょん式 Union-Find
struct UnionFind
{
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x)
    {
        return -par[root(x)];
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<P> AB(m);
    rep(i, m)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        AB[i].first = a;
        AB[i].second = b;
    }

    ll ans = 0;
    //iコめの辺がなかったとき橋になるか？
    rep(i, m)
    {
        UnionFind uf(n);
        rep(j, m)
        {
            if (j == i)
                continue;
            uf.merge(AB[j].first, AB[j].second);
        }

        //橋チェック
        bool ok = false;
        rep(p, n)
        {
            rep(q, n)
            {
                if (p == q)
                    continue;
                if (!uf.issame(p, q))
                {
                    ok = true;
                }
            }
        }
        if (ok)
            ans++;
    }
    cout << ans << endl;
}