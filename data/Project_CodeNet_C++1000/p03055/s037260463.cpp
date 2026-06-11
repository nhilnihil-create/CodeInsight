
#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i) 
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int MOD = 1000000000 + 7;
const static int INT_INF = 999999999;
const static llong INF = 1LL << 60;
const static double eps = 1e-6;
const static int dx[] = {1, 0, -1, 0};
const static int dy[] = {0, 1, 0, -1};

vector<int> dist;
vector<bool> visited;
vector<vector<pair<int, int> > > G; // {connected vertex, cost}

void dfs(int v) {
    visited[v] = true;

    rep(i, (int)G[v].size()) {
        if (visited[G[v][i].first]) continue;
        dist[G[v][i].first] = dist[v] + G[v][i].second;
        dfs(G[v][i].first);
    }

    return;
}

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    G.resize(n);
    rep(i, n - 1) {
        int s, t;
        cin >> s >> t;
        --s, --t;
        G[s].push_back(make_pair(t, 1)), G[t].push_back(make_pair(s, 1));
    }

    dist.resize(n);
    visited.resize(n);
    rep(i, n) {
        dist[i] = 0;
        visited[i] = false;
    }
    dfs(0);

    int farthest_v, cmp = -1;
    rep(i, n) {
        if (dist[i] >= cmp) {
            farthest_v = i;
            cmp = dist[i];
        }
    }

    rep(i, n) {
        dist[i] = 0;
        visited[i] = false;
    }
    dfs(farthest_v);

    cmp = -1;
    int diameter;
    rep(i, n) {
        if (dist[i] >= cmp) {
            diameter = dist[i];
            cmp = dist[i];
        }
    }

    if (diameter % 3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;

    return 0;
}