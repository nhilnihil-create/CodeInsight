#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

struct UnionFind
{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N)
    { // 最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
            par[i] = i;
    }

    int root(int x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {                     // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return;   //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pint> ab(m);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b, --a, --b;
        ab[i] = pint(a, b);
    }
    reverse(ab.begin(), ab.end());

    vector<ll> ans(m);
    ll incom = n * (n - 1LL) / 2;

    UnionFind tree(n);
    vector<int> connect(n, 1);
    rep(i, m)
    {
        ans[i] = incom;
        int a = ab[i].first;
        int b = ab[i].second;

        if (!tree.same(a, b))
        {
            int &at = connect[tree.root(b)];
            int bt = connect[tree.root(a)];
            incom -= at * ll(bt);
            tree.unite(a, b);
            at += bt;
        }
    }

    for (int i = m - 1; i >= 0; --i)
        cout << ans[i] << endl;
}