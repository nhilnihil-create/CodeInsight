#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

ll const MAX_V = 100;

struct edge {
    ll to, cost;
};
vector<edge> G[MAX_V];

ll d[MAX_V];             // 距離計算
typedef pair<ll, ll> P;  // first: 最短距離, second: 頂点番号

void dijkstra(ll s, ll V) {
    // greater<P>を指定することで、firstが小さい順から取り出せる
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d + V, INF);

    // 始点をpushする
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        // cout << "----" << endl;
        // for (ll i = 0; i < V; i++) cout << i << ": " << d[i] << ", ";
        // cout << endl;

        priority_queue<P, vector<P>, greater<P>> que_tmp = que;
        while (!que_tmp.empty()) {
            // cout << que_tmp.top().first << ", " << que_tmp.top().second <<
            // endl;
            que_tmp.pop();
        }

        P p = que.top();
        que.pop();

        // 優先度が最も高い頂点の番号を調べる
        ll v = p.second;

        // push時の最短距離から、dが更新されていたら
        // dが確定したとみなし無視
        if (d[v] < p.first) continue;

        for (ll i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];

            // 仮の最短距離と頂点の組をpush
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    ll H, W;
    cin >> H >> W;
    // vector<vector<ll>> c(9, vector<ll>(9, 0));
    vector<vector<ll>> A(H, vector<ll>(W, 0));
    rep(i, 10) {
        rep(j, 10) {
            ll c;
            cin >> c;
            edge et = {j, c};
            G[i].push_back(et);
        }
    }

    rep(i, H) {
        rep(j, W) { cin >> A[i][j]; }
    }

    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            // cout << "i:" << i << ", j" << j << endl;
            if (A[i][j] == -1) {
                continue;
            }
            dijkstra(A[i][j], 10);
            ans += d[1];
        }
    }

    cout << ans << endl;

    return 0;
}