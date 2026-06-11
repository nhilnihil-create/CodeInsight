#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

const int MAX_H = 50, MAX_W = 50;

int H, W;
char s[MAX_H][MAX_W];

int cnt_white = 0;
int d[MAX_H][MAX_W];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> s[i][j];
            if (s[i][j] == '.') cnt_white++;
        }
    }

    REP(i, H) {
        REP(j, W) d[i][j] = 0;
    }

    queue<pair<int, int>> Q;
    Q.push(MP(0, 0));
    d[0][0] = 1;

    while (Q.size()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        REP(i, 4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (s[nx][ny] == '#' || d[nx][ny] != 0) continue;
            Q.push(MP(nx, ny));
            d[nx][ny] = d[x][y] + 1;
        }
    }

    int score = cnt_white - d[H-1][W-1];
    if (d[H-1][W-1] == 0) score = -1;
    PRINT(score);

    return 0;
}