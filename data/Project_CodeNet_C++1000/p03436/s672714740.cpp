#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int INF = 10000000;
const int H_MX = 50, W_MX = 50;
char field[H_MX][W_MX];
int h, w;
int d[H_MX][W_MX];
int d_r[4] = {0, -1, 1, 0}, d_c[4] = {-1, 0, 0, 1};

int bfs() {
    queue<P> que;
    fill(d[0], d[H_MX], INF);
    que.push(P(0, 0));
    d[0][0] = 0;
    while (que.size()) {
        P p = que.front();
        que.pop();
        if (p.first == h - 1 && p.second == w - 1) break;
        for (int i = 0; i < 4; i++) {
            int nr = p.first + d_r[i], nc = p.second + d_c[i];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                if (field[nr][nc] == '.' && d[nr][nc] == INF) {
                    que.push(P(nr, nc));
                    d[nr][nc] = d[p.first][p.second] + 1;
                }
            }
        }
    }

    return d[h - 1][w - 1];
}

int main() {
    cin >> h >> w;
    int white_num = 0;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            cin >> field[r][c];
            if (field[r][c] == '.') white_num++;
        }
    }
    if (bfs() == INF) cout << "-1" << endl;
    else
        cout << white_num - 2 - (bfs() - 1) << endl;

    return 0;
}