#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

// 頂点の持つ情報
struct edge {
    int to;
    int cost;
};

//最短距離と、頂点の番号
using P = pair<int, int>;

int V = 10;
int inf = 1e9;
// グラフと距離
vector<vector<edge>> G(10);
vector<int> d(10);

void dijkstra(int s) {
    // Pの最初の値（距離）が小さい順で並べるpriority_queue
    priority_queue<P, vector<P>, greater<P>> que;
    // 距離をinfで初期化
    d.assign(V, inf);
    d[s] = 0;
    que.push({0, s});

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        //　戻る場合や他の方が早い場合は最短にならないので飛ばす
        if (d[v] < p.first)
            continue;

        for (int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            // 他より早い場合は更新
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    int Y, X;
    cin >> Y >> X;
    vector<vector<int>> wall(Y, vector<int>(X));
    rep(i, 10) {
        rep(j, 10) {
            int cost;
            cin >> cost;
            G[j].push_back({i, cost});
        }
    }

    map<int, int> ma;
    rep(i, Y) {
        rep(j, X) {
            cin >> wall[i][j];
            if (wall[i][j] != -1 && wall[i][j] != 1)
                ma[wall[i][j]]++;
        }
    }

    dijkstra(1);
    ll ans = 0;
    for (auto m : ma) {
        ans += (d[m.first] * m.second);
    }

    cout << ans << endl;
}