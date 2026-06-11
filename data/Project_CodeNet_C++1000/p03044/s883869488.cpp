#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, int> Edge; // 辺，辺の先の点
typedef pair<ll, int> P; // 最短距離，点
using Graph = vector<vector<Edge>>;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back(Edge(w, v));
        G[v].push_back(Edge(w, u));
    }
    vector<ll> d(N, INF_64);
    vector<int> ans(N);
    priority_queue<P> que;
    que.push(P(0, 0));
    ans[0] = 0;

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first)
            continue;
        d[v] = p.first;
        if (d[v] % 2 == 0) {
            ans[v] = 0;
        } else {
            ans[v] = 1;
        }
        for (auto e : G[v]) {
            int nv = e.second;
            if (d[nv] < d[v] + e.first)
                continue;
            que.push(P(d[v] + e.first, nv));
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
