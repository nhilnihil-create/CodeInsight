#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dist;

void dfs(int v, int d) {
    if (dist[v] != INT_MAX) return;
    dist[v] = d;
    rep(i, sz(g[v])) {
        dfs(g[v][i].first, d + g[v][i].second);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, INT_MAX);
    rep(i, m) {
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        g[l].emplace_back(r, d);
        g[r].emplace_back(l, -1 * d);
    }
    rep(i, n) {
        if (dist[i] != INT_MAX) continue;
        dfs(i, 0);
    }
    rep(i, n) {
        rep(ii, sz(g[i])) {
            if ((dist[i] + g[i][ii].second) != dist[g[i][ii].first]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}