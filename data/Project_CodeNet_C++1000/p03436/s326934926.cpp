#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    vector<vector<int>> dist(h, vector<int>(w, -1));
    int ans = h * w;
    for (auto &s: grid) {
        cin >> s;
        ans -= count(s.begin(), s.end(), '#');
    }
    queue<pair<int, int>> q;
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    q.emplace(0, 0);
    dist[0][0] = 1;
    while (!q.empty()) {
        auto v = q.front();q.pop();
        int px = v.first, py = v.second;
        for (auto d: dir) {
            int x = v.first + d.first, y = v.second + d.second;
            if (x < 0 || y < 0 || x >= h || y >= w) continue;
            if (dist[x][y] != -1) continue;
            if (grid[x][y] == '#') continue;
            dist[x][y] = dist[px][py] + 1;
            q.emplace(x, y);
        }
    }
    if (dist[h-1][w-1] == -1) {
        cout << -1 << endl;
        return 0;
    }
    ans -= dist[h-1][w-1];
    cout << ans << endl;
    return 0;
}