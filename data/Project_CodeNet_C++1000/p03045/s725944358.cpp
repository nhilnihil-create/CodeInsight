#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 10000000;

using Graph = vector<vector<int>>;
vector<bool>seen(100005, false);
void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto nv : G[v]) {
        if (seen[nv]) continue;
        dfs(G, nv);
    }
}

int main() {
    int N, M;
    int ans = 0;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 0; i < N; i++) {
        if (!seen[i]) {
            ans++;
            dfs(G, i);
        }
    }
    cout << ans << endl;
}

