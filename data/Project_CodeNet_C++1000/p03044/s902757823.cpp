#include <iostream>
#include <vector>
using namespace std;
const int nil = -10;

typedef vector<vector<pair<int, int>>> graph;
graph G;
vector<int> color;
vector<bool> seen;

void dfs (int now) {
    seen[now] = true;
    for (auto i: G[now]) {
        if (seen[i.first]) continue;
        else {
            if (i.second) {
                color[i.first] = 1 - color[now];
            } else {
                color[i.first] = color[now];
            }
            dfs(i.first);
        }
    }
}

int main() {
    int n;
    cin >> n;
    G.resize(n);
    color.resize(n);
    seen.resize(n, false);
    for (int i=0; i<n-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back(make_pair(v, w%2));
        G[v].push_back(make_pair(u, w%2));
    }
    color[0] = 0;
    dfs(0);
    for (int i=0; i<n; ++i) {
        cout << color[i] << endl;
    }
}