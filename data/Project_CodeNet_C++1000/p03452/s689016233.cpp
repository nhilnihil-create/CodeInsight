#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
using ll = long long;
using namespace std;

struct weighted_UnionFind
{
    vector<int> rnk, par, diff_weight;

    weighted_UnionFind(int N) : par(N), rnk(N), diff_weight(N)
    {
        for (int i = 0; i < N; ++i)
        {
            rnk[i] = 1;
            par[i] = i;
            diff_weight[i] = 0;
        }
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
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }
    int weight(int x)
    {
        root(x);
        return diff_weight[x];
    }
    void unite(int x, int y, int w)
    {
        w += weight(x);
        w -= weight(y);

        x = root(x);
        y = root(y);

        if (x == y)
            return;

        if (rnk[x] < rnk[y])
        {
            swap(x, y);
            w = -w;
        }

        if (rnk[x] == rnk[y])
            rnk[x]++;
        par[y] = x;
        diff_weight[y] = w;
    }

    int diff(int x, int y)
    {
        return weight(y) - weight(x);
    }
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
};
int main(void)
{
    int N, M;
    cin >> N >> M;
    weighted_UnionFind uf(N);
    for (int i = 0; i < M; ++i)
    {
        int L, R, D;
        cin >> L >> R >> D;
        L--;
        R--;
        if (uf.same(L, R))
        {
            int dif = uf.diff(L, R);
            if (dif != D)
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            uf.unite(L, R, D);
        }
    }
    cout << "Yes" << endl;
    return 0;
}