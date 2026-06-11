#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

template <typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>> &G) {
    const T INF = numeric_limits<T>::max();
    using P     = pair<T, int>;
    int n       = G.size();
    vector<T> d(n, INF);
    vector<int> b(n, -1);
    priority_queue<P, vector<P>, greater<P>> q;
    d[s] = 0;
    q.emplace(d[s], s);
    while (!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        for (auto &e : G[v]) {
            int u = e.first;
            T c   = e.second;
            if (d[u] > d[v] + c) {
                d[u] = d[v] + c;
                b[u] = v;
                q.emplace(d[u], u);
            }
        }
    }
    return d;
}

int main() {
    int n;
    cin >> n;
    vector<vector<pii>> edges(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].emplace_back(b, 1);
        edges[b].emplace_back(a, 1);
    }
    auto dist = dijkstra(0, edges);
    int idx   = 0;
    int maxi  = 0;
    for (int i = 0; i < n; ++i) {
        if (chmax(maxi, dist[i]))
            idx = i;
    }
    auto dist2 = dijkstra(idx, edges);
    int diag   = 0;
    for (int i = 0; i < n; ++i) {
        chmax(diag, dist2[i]);
    }
    if (diag % 3 == 1)
        cout << "Second"
             << "\n";
    else
        cout << "First"
             << "\n";

    return 0;
}