#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000

struct edge {
    int to;
    int cost;
};
vector<vector<edge>> G(pow(10, 5) + 1);

void dfs(int s, vector<int> &color) {
    for (auto e : G[s]) {
        if (color[e.to] != -1)
            continue;
        if (e.cost % 2 == 0)
            color[e.to] = color[s];
        else if (color[s] == 0)
            color[e.to] = 1;
        else
            color[e.to] = 0;
        dfs(e.to, color);
    }
}

int main() {
    int N;
    cin >> N;
    G.resize(N, vector<edge>());
    vector<int> color(N, -1);
    int s;
    rep(i, N - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    int ma = 0;
    rep(i, N) {
        if (G[i].size() > ma) {
            ma = G[i].size();
            s = i;
        }
    }

    color[s] = 0;
    int cnt = 0;
    dfs(s, color);

    rep(i, N) { cout << color[i] << endl; }
}