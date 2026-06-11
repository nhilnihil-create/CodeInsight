#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#define MAX 1000
typedef pair<int, int> P;
int h, w;
char a[MAX][MAX];
int d[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<P> que;

void bfs() {
    while (que.size()) {
        P p = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && a[ny][nx] == '.' && d[ny][nx] == INT_MAX) {
                d[ny][nx] = d[p.first][p.second] + 1;
                que.emplace(P(ny, nx));
            }
        }
    }
    return;
}


int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                d[i][j] = 0;
                que.emplace(P(i, j));
            }
            else {
                d[i][j] = INT_MAX;
            }
        }
    }
    bfs();
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            chmax(ans, d[i][j]);
        }
    }
    cout << ans << endl;
}