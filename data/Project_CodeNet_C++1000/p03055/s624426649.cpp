#include <bits/stdc++.h>
#define ALL(obj) begin(obj), end(obj)
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
const int INF = 2100100100;
const int MOD = 1e9 + 7;

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long cost;
};
using Graph = vector<vector<Edge>>;

/* tree_diamiter : dfs を用いて重み付き木 T の直径を求める
*/
pair<long long, int> dfs(const Graph &G, int u, int par) {
    pair<long long, int> ret = make_pair(0LL, u);
    for (auto e : G[u]) {
        if (e.to == par) continue;
        auto next = dfs(G, e.to, u);
        next.first += e.cost;
        ret = max(ret, next);
    }
    return ret;
}
long long tree_diamiter(const Graph &G) {
    auto p = dfs(G, 0, -1);
    auto q = dfs(G, p.second, -1);
    return q.first;
}

int main() {
    int n;
    cin >> n;
    Graph T(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        T[s].push_back({t, 1});
        T[t].push_back({s, 1});
    }
    long long w = tree_diamiter(T);
    if ((w + 2) % 3 == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
    return 0;
}
