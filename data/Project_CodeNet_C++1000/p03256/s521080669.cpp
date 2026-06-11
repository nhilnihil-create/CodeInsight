#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tsort(vector<vector<int>> &g) {
    int n = g.size(), k = 0;
    vector<int> ord(n), in(n);
    for (int u = 0; u < n; u++) for (int v: g[u]) in[v]++;
    queue<int> que;
    for (int u = 0; u < n; u++) if (in[u] == 0) que.push(u);
    while (!que.empty()) {
        int u = que.front(); que.pop();
        ord[k++] = u;
        for (int v: g[u]) if (--in[v] == 0) que.push(v);
    }
    return *max_element(in.begin(), in.end()) == 0 ? ord : vector<int>();
}

int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<int>> g(n * 2);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        if (s[a] == s[b]) {
            g[a].emplace_back(b + n);
            g[b].emplace_back(a + n);
        } else {
            g[a + n].emplace_back(b);
            g[b + n].emplace_back(a);
        }
    }
    cout << (tsort(g).empty() ? "Yes" : "No") << endl;
    return 0;
}
