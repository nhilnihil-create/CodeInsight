#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;
const long long INF = 1LL << 60;
struct Edge
{
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

int main()
{
    ll n;
    cin >> n;
    Graph G(n);
    rep(i, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(Edge(v, w));
        G[v].push_back(Edge(u, w));
    }

    vector<int> ans(n, -1);
    ans[0] = 0;
    queue<int> que;
    que.push(0);
    //BFSで実装
    while (!que.empty())
    {
        int v = que.front();
        que.pop();

        for (auto e : G[v])
        {
            if (ans[e.to] != -1)
                continue;

            if (e.weight % 2 == 0)
                ans[e.to] = ans[v];
            else if (ans[v] == 0)
                ans[e.to] = 1;
            else if (ans[v] == 1)
                ans[e.to] = 0;

            que.push(e.to);
        }
    }

    rep(i, n) cout << ans[i] << endl;
}