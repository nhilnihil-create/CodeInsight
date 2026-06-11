#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
// vector<ll> u, v, w;

vector<P> g[100100];
vector<ll> ans;

void dfs(int cur, int par = -1) {
    for (int j = 0; j < g[cur].size(); j++) {
        if (g[cur][j].first == par) continue;
        if (ans[g[cur][j].first] != -1) continue;

        ans[g[cur][j].first] = (ans[cur] + g[cur][j].second) % 2;
        dfs(g[cur][j].first, cur);
    }
}

int main() {
    cin >> N;
    rep(i, N - 1) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back(P(v, w));
        g[v].push_back(P(u, w));
    }

    ans.resize(N, -1);

    ans[0] = 0;
    dfs(0);

    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }
}