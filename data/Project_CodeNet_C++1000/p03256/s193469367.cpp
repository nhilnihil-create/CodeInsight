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
    string s;
    cin >> s;
    TopologicalSort tp(4 * n);
    vector<vector<int>> edges(4 * n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (s[a] == 'A' && s[b] == 'A') {
            tp.addEdge(a, b + n);
            tp.addEdge(b, a + n);
        } else if (s[a] == 'A' && s[b] == 'B') {
            tp.addEdge(a + n, b + 2 * n);
            tp.addEdge(b + 3 * n, a);
        } else if (s[a] == 'B' && s[b] == 'A') {
            tp.addEdge(b + n, a + 2 * n);
            tp.addEdge(a + 3 * n, b);
        } else if (s[a] == 'B' && s[b] == 'B') {
            tp.addEdge(a + 2 * n, b + 3 * n);
            tp.addEdge(b + 2 * n, a + 3 * n);
        }
    }
    auto sorted = tp.build();
    if (sorted.size() == 4 * n)
        cout << "No"
             << "\n";
    else
        cout << "Yes"
             << "\n";
    return 0;
}