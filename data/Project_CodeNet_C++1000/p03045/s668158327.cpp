#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto v : g[u]) {
                    if (visited[v]) continue;
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    cout << ans;

    return 0;
}