#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct edge {
    int to;
    int cost;
};

typedef vector<vector<edge>> graph;

bool ret = true;
vector<bool> visited;
vector<int> dis;

void dfs(graph &g, int nowv, int nowd) {
    visited[nowv] = true;
    dis[nowv] = nowd;
    for (auto next:g[nowv]) {
        int nextd = nowd + next.cost;
        if (!visited[next.to])dfs(g, next.to, nextd);
        else if (dis[next.to] != nextd)ret = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        g[l].push_back({r, d});
        g[r].push_back({l, -d});
    }

    visited = vector<bool>(n);
    dis = vector<int>(n);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(g, i, 0);
    }

    cout << (ret ? "Yes" : "No") << endl;
    return 0;
}