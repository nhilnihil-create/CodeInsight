#include <bits/stdc++.h>
#define repd(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

struct UnionFind {
    vector<int> par, rank, diff_weight;

    UnionFind(int N) : par(N), rank(N), diff_weight(N) {
        rep(i, N) par[i] = i, rank[i] = 0, diff_weight[i] = 0;
    }

    int root(int x) {
        if (par[x] == x) return x;
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    int weight(int x) {
        root(x);
        return diff_weight[x];
    }

    int diff(int x, int y) {
        return weight(y) - weight(x);
    }

    bool unite(int x, int y, int w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) {
            swap(x, y);
            w = -w;
        }
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;

        return true;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int N, M;
    bool flag = true;
    cin >> N >> M;

    UnionFind tree(N);
    rep(i, M)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        if (tree.same(x, y)) {
            if (tree.diff(x, y) != z) {
                flag = false;
            }
        }
        else {
            tree.unite(x, y, z);
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
