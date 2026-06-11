#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

template <typename T>
struct edge
{
    int src, to;
    T cost;
    edge(int to, T cost) : src(-1), to(to), cost(cost) {}
    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;

template <typename T>
using WeightedGraph = vector<Edges<T>>;

template <typename T>
using UnweightedGraph = vector<vector<T>>;

template <typename T>
using Matrix = vector<vector<T>>;

template <typename T>
pair<T, int> dfs(const WeightedGraph<T> &G, int v, int par)
{
    pair<T, int> res = {0, v};
    for (auto &e : G[v])
    {
        if (e.to == par)
            continue;
        auto dist = dfs(G, e.to, v);
        dist.first += e.cost;
        res = max(res, dist);
    }
    return res;
}

template <typename T>
T tree_diameter(const WeightedGraph<T> &G)
{
    auto p = dfs(G, 0, -1);
    auto q = dfs(G, p.second, -1);
    return q.first;
}

int main()
{
    int N;
    cin >> N;
    WeightedGraph<int> G(N);
    for (int i = 0; i + 1 < N; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[x].emplace_back(y, 1);
        G[y].emplace_back(x, 1);
    }
    cout << (tree_diameter(G) % 3 != 1 ? "First" : "Second") << "\n";
}