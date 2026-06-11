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
    // すべての白マスの数を数える
    int white = 0;

    rep(y, h) {
        string s;
        cin >> s;
        rep(x, w) {
            map[y][x] = s[x];
            visit[y][x] = -1;
            if (s[x] == '.') white++;
        }
    }

    P start = P(0, 0);
    P goal = P(h-1, w-1);
    q.push(start);
    // startとgoalを含めて使ったマスの数を数えたいので1からスタートする
    visit[start.first][start.second] = 1;

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
                q.push(P(y, x));
            };
            check(v.first + 1, v.second);
            check(v.first, v.second + 1);
            check(v.first - 1, v.second);
            check(v.first, v.second - 1);
        }
    };
    bfs();

    if (visit[goal.first][goal.second] == -1) {
        cout << -1 << endl;
    } else {
        cout << white - visit[goal.first][goal.second] << endl;
    }
     
    return 0;
}

