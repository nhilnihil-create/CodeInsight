#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using edge = pair<ll, P>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
using Graph = vector<vector<ll>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

vector<int> topological_sort(const Graph &graph) {
    int N = graph.size();
    vector<int> in_cnt(N, 0);
    for (int i = 0; i < N; ++i) {
        for (int v : graph[i]) {
            in_cnt[v]++;
        }
    }
    queue<int> S;
    for (int i = 0; i < N; ++i) {
        if (in_cnt[i] == 0) S.push(i);
    }

    vector<int> res(N, -1);
    res[S.front()] = 0;
    while (!S.empty()) {
        int u = S.front(); S.pop();
        for (int v : graph[u]) {
            in_cnt[v]--;
            if (in_cnt[v] == 0) {
                S.push(v);
                res[v] = u + 1;
            }
        }
    }
    return res;
}


void Main() {
    int N, M;
    cin >> N >> M;
    Graph graph(N);
    rep(i, N + M - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }

    auto sorted = topological_sort(graph);
    rep(i, N) {
        cout << sorted[i] << endl;
    }


}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
