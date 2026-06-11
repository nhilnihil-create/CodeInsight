#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m; cin >> n >> m;
    vector<pii> edges;
    vector<int> in_cnt(n, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1 + m; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        in_cnt[b]++;
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (in_cnt[i] == 0) {
            root = i;
        }
    }

    queue<int> q;
    q.push(root);
    vector<int> parent(n, -1);
    parent[root] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size();i ++) {
            int dst = adj[cur][i];
            in_cnt[dst]--;
            if (in_cnt[dst] == 0) {
                q.push(dst);
                parent[dst] = cur + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << parent[i] << endl;
    }

    return 0;
}
