#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int main(int argc, char const *argv[])
{
    int h, w;
    cin >> h >> w;

    int INF = h*w + 1;

    string s[h];
    int tmp[h][w];
    for (int i = 0; i < h; i ++) {
        cin >> s[i];
        for (int j = 0; j < w; j ++) {
            if (s[i][j] == '.') {
                tmp[i][j] = INF;
            } else {
                tmp[i][j] = 0;
            }
        }
    }

    queue<P> que;
    int x, y, nx, ny;
    P coor;
    int res = 0;

    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            if (s[i][j] == '#') {
                que.push(make_pair(i, j));
            }
        }
    }
    
    // bfs を黒ますスタート白ます辿りで行う
    while(!que.empty()) {
        coor = que.front();
        que.pop();
        x = coor.first;
        y = coor.second;

        for (int dx = -1; dx < 2; dx ++) {
            for (int dy = -1; dy < 2; dy ++) {
                if (dx * dy != 0 || dx == dy) {
                    continue;
                }
                nx = x + dx;
                ny = y + dy;
                if (
                    0 <= nx && nx < h &&
                    0 <= ny && ny < w &&
                    s[nx][ny] == '.' &&
                    tmp[x][y] + 1 < tmp[nx][ny]
                ) {
                    tmp[nx][ny] = tmp[x][y] + 1;
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }

    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            if (tmp[i][j] > res) {
                res = tmp[i][j];
            }
        }
    }
    cout << res << endl;
    return 0;
}
