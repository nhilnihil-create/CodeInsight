#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
Graph G;
vector<int> color;
using ll = long long;
// white 0, black 1

bool dfs(int cn, int cn_color){
    color[cn] = cn_color;
    for (auto next: G[cn]){
        if (color[next] != -1) {
            if (color[next] == cn_color) return false;
            continue;
        }
        if (!dfs(next, 1 - cn_color)) return false;
    }
    return true;
    // bool ok = true;
    // for (auto next: G[cn]){
    //     if (color[next] == -1) {
    //         color[next] = 1 - cn_color;
    //         ok = dfs(next, color[next]);
    //         continue;
    //     }
    //     if (cn_color == color[next]) return false;
    //     else continue;
    // }
    // return ok;
}

int main() {
    ll N, M;
    cin >> N >> M;
    G.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    color.assign(N, -1);
    bool is_bipartite = dfs(0, 0);
    ll ans = 0;
    ll B = 0;
    if (is_bipartite) {
        B = count(color.begin(), color.end(), 1);
        ans = B * (N - B) - M;
    }
    else ans = (N - 1) * N / 2 - M;
    cout << ans << endl;
    return 0;
}