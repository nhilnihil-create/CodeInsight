#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> f(n);
    for (int i = 0; i < n; ++i)
        cin >> f[i];
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (f[i][j] == '#')
                q.emplace(i, j);
        }
    }
    int count = 0;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    bool done = true;
    do {
        done = true;
        queue<pair<int, int>> nq;
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front(); q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (f[nx][ny] == '.') {
                    f[nx][ny] = '#';
                    nq.emplace(nx, ny);
                }
            }
        }
        if (!nq.empty()) {
            ++count;
            done = false;
        }
        swap(q, nq);
    } while (!done);

    cout << count << "\n";
    return 0;
}
