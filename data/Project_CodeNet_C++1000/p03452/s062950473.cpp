#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100100;

vector<pair<int, int>> g[N];
int used[N], x[N];

void dfs(int v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (used[u.first]) {
            if (x[u.first] - x[v] != u.second) {
                cout << "No";
                exit(0);
            }
        } else {
            x[u.first] = x[v] + u.second;
            dfs(u.first);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int l, r, d;
        cin >> l >> r >> d;
        g[l].push_back({r, d});
        g[r].push_back({l, -d});
    }
    for (int i = 1; i <= n; ++i) {
        x[i] = LONG_MAX;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            x[i] = 0;
            dfs(i);
        }
    }
    cout << "Yes";
    return 0;
}