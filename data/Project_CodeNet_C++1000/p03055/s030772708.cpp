#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)

pair<int, int> bfs(const vector<vector<int>> &G, int s) {
    pair<int, int> res;
    queue<int> que;
    vector<int> dist((int)G.size(), -1);
    que.push(s);
    dist[s] = 0;
    while(!que.empty()) {
        int cur = que.front(); que.pop();
        for(auto &to : G[cur]) {
            if(dist[to] == -1) {
                que.push(to);
                dist[to] = dist[cur] + 1;
                res = make_pair(to, dist[to]);
            }
        }
    }
    return res;
}

int Diameter(const vector<vector<int>> &G) {
    auto tmp = bfs(G, 0);
    auto res = bfs(G, tmp.first);
    return res.second;
}

void solve() {
    int N; cin >> N;
    vector<vector<int>> G(N);
    rep(i, 0, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << (Diameter(G) % 3 != 1 ? "First" : "Second") << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
