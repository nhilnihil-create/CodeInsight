#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int INF = 10000000;
const int H_MX = 1000, W_MX = 1000;
int h, w;
char field[H_MX][W_MX];
int d[H_MX][W_MX];
int d_r[4] = {0, -1, 1, 0}, d_c[4] = {-1, 0, 0, 1};

int bfs() {
    int blk_num = 0;
    int op_num = 0;
    queue<P> que;
    fill(d[0], d[H_MX], INF);
    //最初に黒のマスをqueにすべて入れる
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (field[r][c] == '#') {
                que.push(P(r, c));
                d[r][c] = 0;
                blk_num++;
            }
        }
    }
    while (blk_num < h * w) {
        P p = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nr = p.first + d_r[i], nc = p.second + d_c[i];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                if (field[nr][nc] == '.' && d[nr][nc] == INF) {
                    que.push(P(nr, nc));
                    d[nr][nc] = d[p.first][p.second] + 1;
                    op_num = d[nr][nc];
                    blk_num++;
                }
            }
        }
    }
    return op_num;
}

int main() {
    cin >> h >> w;
    //入力
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            cin >> field[r][c];
        }
    }

    cout << bfs() << endl;

    return 0;
}