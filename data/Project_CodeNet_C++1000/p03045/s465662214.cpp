#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;

const int MAXN = (int)1e5 + 5;
vector<int> adjList[MAXN];
bool vis[MAXN];

void dfs(int u) {
    vis[u] = 1;
    for (int v : adjList[u]) {
        if (!vis[v])
            dfs(v);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ++ans;
            dfs(i);
        }
    }

    cout << ans << '\n';




    return 0;
}