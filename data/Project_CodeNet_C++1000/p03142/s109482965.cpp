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

// topologically sort the directed graph
// 0-indexed

struct TopologicalSort {
    int n;
    vector<set<int>> G;
    vector<bool> used;
    vector<int> indeg, p;

    TopologicalSort(int size) : n(size), G(n), used(n), indeg(n), p(0) {}

    void addEdge(int s, int t) { G[s].insert(t); }
    void bfs(int s) {
        queue<int> q;
        q.push(s);
        used[s] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            p.push_back(v);
            for (int u : G[v]) {
                indeg[u]--;
                if (indeg[u] == 0 && !used[u]) {
                    used[u] = 1;
                    q.push(u);
                }
            }
        }
    }
    // returns topologically sorted nodes
    vector<int> build() {
        fill(used.begin(), used.end(), 0);
        fill(indeg.begin(), indeg.end(), 0);
        for (int i = 0; i < n; ++i) {
            for (int v : G[i])
                indeg[v]++;
        }
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0 && !used[i])
                bfs(i);
        }
        return p;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    TopologicalSort tp(n);
    vvi rev(n);
    for (int i = 0; i < n - 1 + m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        tp.addEdge(a, b);
        rev[b].push_back(a);
    }
    auto sorted = tp.build();
    vi ord(n);
    for (int i = 0; i < n; ++i) {
        ord[sorted[i]] = i;
    }
    vi ret(n, 0);
    auto f = [&](int l, int r) { return ord[l] < ord[r]; };
    for (auto &t : sorted) {
        if (rev[t].size() != 0) {
            sort(rev[t].begin(), rev[t].end(), f);
            ret[t] = *rev[t].rbegin() + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ret[i] << "\n";
    }

    return 0;
}