#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

struct edge {
    int to, cost;
};

int main() {
    int n;
    cin >> n;

    vector<vector<edge>> G(n);

    rep(i, n - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        w %= 2;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }

    vector<int> ans(n, -1);
    queue<int> que;
    que.push(0);

    ans[0] = 0;
    while (!que.empty()) {
        int now = que.front();
        que.pop();

        rep(i, G[now].size()) {
            int to = G[now][i].to;
            int cost = G[now][i].cost;

            if (ans[to] != -1)
                continue;

            ans[to] = (ans[now] + cost) % 2;
            que.push(to);
        }
    }

    for (int &a : ans)
        cout << a << "\n";

    return 0;
}