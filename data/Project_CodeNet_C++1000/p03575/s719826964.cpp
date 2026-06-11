#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int n, m;
bool visited[50];
bool graph[50][50];

void dfs(int i) {
    visited[i] = 1;
    rep(j, n) {
        if (!graph[i][j] || visited[j]) continue;
        dfs(j);
    }
}

int main() {
    cin >> n >> m;
    int a[50], b[50];
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = 1;
    }

    int ans = 0;
    rep(i, m) {
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = 0;

        rep(j, n) visited[j] = 0;
        dfs(0);
        bool bridge = false;
        rep(j, n) if (!visited[j]) bridge = true;
        if (bridge) ans++;

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = 1;
    }

    cout << ans << endl;
    return 0;
}
