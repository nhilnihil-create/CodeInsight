#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int main(int argc, char const *argv[])
{
    int h, w;
    cin >> h >> w;

    char s[h][w], res;
    int tmp[h][w];
    int white = 0;

    for (int i = 0; i < h * w; i ++) {
        cin >> res;
        if (res == '.') {
            white ++;
        }
        s[i/w][i%w] = res;
        tmp[i/w][i%w] = -1;
    }

    // 最短距離を求めれば、それと白いマスの差の絶対値が答え
    queue<P> que;
    que.push(make_pair(0, 0));
    tmp[0][0] = 0;
    int x, y, nx, ny;
    P coor;

    while (!que.empty()) {
        coor = que.front();
        que.pop();
        x = coor.first;
        y = coor.second;
        for (int dx = -1; dx < 2; dx ++) {
            for (int dy = -1; dy < 2; dy ++) {
                nx = x + dx;
                ny = y + dy;
                if (
                    dx * dy == 0 && dx != dy &&
                    0 <= nx && nx < h &&
                    0 <= ny && ny < w &&
                    s[nx][ny] == '.' &&
                    tmp[nx][ny] == -1
                ) {
                    if (nx == h-1 && ny == w-1) {
                        printf("%d\n", white - tmp[x][y] - 2);
                        return 0;
                    }
                    tmp[nx][ny] = tmp[x][y] + 1;
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}
