#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;

const int MAXN = (int)1e5 + 5;
vector<pair<int, int>> adjList[MAXN];
map<int, int> mp;

int getColor(int u) {
    return mp[u];
}

void setColor(int u, int color) {
    mp[u] = color;
}

void dfs(int u, int par, bool odd) {
    setColor(u, odd);
    for (auto p : adjList[u]) {
        int v = p.first;
        int w = p.second;
        if (v == par)
            continue;
        dfs(v, u, (odd + (w & 1)) % 2);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
        edges.push_back({u, v});
    }


    dfs(1, 0, 0);

    for (int i = 1; i <= n; ++i) {
        cout << getColor(i) << '\n';
    }




    return 0;
}