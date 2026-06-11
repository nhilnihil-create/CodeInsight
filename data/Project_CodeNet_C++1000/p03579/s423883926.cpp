#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

#include <vector>

struct UnionFind
{
    vector<int> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
    {
        x = root(x), y = root(y);
        if (x == y)
            return false;
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int root(int k)
    {
        if (data[k] < 0)
            return k;
        data[k] = root(data[k]);
        return data[k];
    }

    int size(int k)
    {
        return (-data[root(k)]);
    }

    bool same(int x, int y)
    {
        return (root(x) == root(y));
    }
};

struct BipartiteGraph : UnionFind
{
    vector<int> color;

    BipartiteGraph(int N) : color(2 * N, -1), UnionFind(2 * N) {}

    /*
    color u, v by same color ->  unite(u, v) && unite(u + N, v + N)
    color u, v by different color -> unite(u + N, v) && unite(u, v + N)
    */

    bool BG_unite(int u, int v, bool same)
    {
        int N = ((int)color.size()) / 2;
        if (same == true)
        {
            unite(u, v);
            unite(u + N, v + N);
        }
        else
        {
            unite(u + N, v);
            unite(u, v + N);
        }
    }

    // 0, 1, ..., v - 1 -> left; v, v + 1, ..., 2 * v - 1 -> right;
    bool BG_coloring()
    {
        int N = ((int)color.size()) / 2;
        for (int i = 0; i < N; i++)
        {
            int s = root(i), t = root(i + N);
            if (s == t)
                return false;
            if (color[s] < 0)
                color[s] = 0, color[t] = 1;
        }
        return true;
    }

    //return k's color
    bool operator[](int v)
    {
        return (bool)(color[root(v)]);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    BipartiteGraph bg(N);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        bg.BG_unite(a, b, 0);
    }

    if (bg.BG_coloring() == false)
    {
        cout << ((ll)N * (ll)(N - 1LL)) / 2 - (ll)M << endl;
    }
    else
    {
        map<bool, int> mp;
        for (int i = 0; i < N; i++)
        {
            mp[bg[i]]++;
        }
        cout << (ll)mp[false] * (ll)mp[true] - (ll)M << endl;
    }
}
