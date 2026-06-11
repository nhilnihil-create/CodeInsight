#include <bits/stdc++.h>

using namespace std;

const int limit = 100010;
vector<vector<int>> xy(limit);
vector<bool> visited(limit);

void dfs(int v){
    visited[v] = true;
    for (auto &e : xy[v]){
        if (! visited[e])
        {
            dfs(e);
        }
    }
}

void solve() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        z = z%2;
        xy[x].push_back(y);
        xy[y].push_back(x);
    }
    int ans;
    ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}