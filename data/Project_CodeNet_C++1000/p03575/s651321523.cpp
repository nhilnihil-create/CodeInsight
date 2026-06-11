#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1

using namespace std;
const int INF = 1e18;

//Graph
struct edge
{
    int to;
    int cost;
};
using Graph = vector<vector<edge>>;

Graph G;
struct UnionFind
{
    vector<int> data;
    void init(int n) { data.assign(n, -1); }
    bool unionSet(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (data[y] < data[x])
                swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
};

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    rep(i, m)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        UnionFind uf;
        uf.init(n);
        for (int j = 0; j < m; j++)
        {
            if (i == j)
                continue;
            uf.unionSet(a[j], b[j]);
        }

        bool isOK = true;
        rep(x, n)
        {
            rep(y, n)
            {
                if (x == y)
                    continue;
                if (x < y)
                    continue;
                if (!uf.findSet(x, y))
                    isOK = false;
            }
        }
        if (isOK == false)
            ans++;
    }

    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
