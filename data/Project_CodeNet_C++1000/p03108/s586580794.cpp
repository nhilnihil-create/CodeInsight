#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind
{
    vector<int> par;  // 親ノード
    vector<int> rank; // ランク
    vector<int> size; // ランク

    UnionFind(int n = 1)
    {
        init(n);
    }

    void init(int n = 1)
    {
        par.resize(n);
        rank.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i)
            par[i] = i, rank[i] = 0, size[i] = 1;
    }

    int root(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        else
        {
            int r = root(par[x]);
            return par[x] = r;
        }
    }
    int cnt(int x)
    {
        return size[root(x)];
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
        if (rank[x] < rank[y])
            swap(x, y);
        if (rank[x] == rank[y])
            ++rank[x];
        par[y] = x;
        size[x] += size[y];
        return true;
    }
};

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<pair<int, int>> vec(M);
    for (ll i = 0; i < M; i++)
    {
        cin >> vec[i].first >> vec[i].second;
        vec[i].first--;
        vec[i].second--;
    }

    UnionFind uf(N);
    vector<ll> his(M);
    ll cnt = N * (N - 1) / 2;
    for (ll i = M - 1; i >= 0; i--)
    {
        his[i] = cnt;
        if (uf.issame(vec[i].first, vec[i].second))
        {
            continue;
        }
        cnt -= uf.cnt(vec[i].first) * uf.cnt(vec[i].second);
        uf.merge(vec[i].first, vec[i].second);
    }

    for (ll i = 0; i < M; i++)
    {
        cout << his[i] << endl;
    }
    return 0;
}