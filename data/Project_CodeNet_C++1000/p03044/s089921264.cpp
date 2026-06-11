#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> to(n), cost(n);
    rep(i, n - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        to[a].push_back(b);
        cost[a].push_back(w);
        to[b].push_back(a);
        cost[b].push_back(w);
    }

    vector<int> ans(n, -1);
    queue<int> que;

    ans[0] = 0;
    que.push(0);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        rep(i, to[v].size()) {
            int u = to[v][i];
            int w = cost[v][i];

            if (ans[u] != -1)
                continue;
            ans[u] = (ans[v] + w) % 2;
            que.push(u);
        }
    }

    rep(i, n) cout << ans[i] << "\n";

    return 0;
}