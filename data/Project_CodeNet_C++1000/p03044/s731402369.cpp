#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

#define NIL -1

int main() {
    int N; cin >> N;
    vector<vector<pair<int, int>>> G(N);
    int u, v, w;
    rep(i, N-1) {
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    vector<int> ans(N, NIL);
    queue<int> q;
    q.push(0);
    ans[0] = 0;
    int tmp;
    while (!q.empty()) {
        tmp = q.front(); q.pop();
        rep(i, G[tmp].size()) {
            if (ans[G[tmp][i].first] == NIL) {
                ans[G[tmp][i].first] = abs(G[tmp][i].second%2 - ans[tmp]);
                q.push(G[tmp][i].first);
            }
        }
    }
    rep(i, N) cout << ans[i] << endl;
}
