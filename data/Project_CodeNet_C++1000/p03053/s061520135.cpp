#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using P = pair<int, int>; 

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> map(h, vector<char>(w));
    vector<vector<int>> visit(h, vector<int>(w));
    queue<P> q;

    rep(y, h) {
        string s;
        cin >> s;
        rep(x, w) {
            map[y][x] = s[x];
            visit[y][x] = -1;
            if (map[y][x] == '#') {
                q.push(P(y, x));
                visit[y][x] = 0;
            }
        }
    }
    auto bfs = [&]() {
        while(!q.empty()) {
            P v = q.front(); q.pop();
            auto check = [&](int y, int x) {
                if (x < 0 || x >= w || y < 0 || y >= h) {
                    return;
                }
                if (map[y][x] == '#') {
                    return;
                }
                if (visit[y][x] != -1) {
                    return;
                }
                visit[y][x] = visit[v.first][v.second] + 1;
                map[y][x] = '#';
                q.push(P(y, x));
            };
            check(v.first + 1, v.second);
            check(v.first, v.second + 1);
            check(v.first - 1, v.second);
            check(v.first, v.second - 1);
        }
    };
    bfs();
    int ans = 0;
    rep(y, h) rep(x, w) {
        ans = max(visit[y][x], ans);
    }
    cout << ans << endl;
    return 0;
}

