#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;

vector<string> maze;
int R, C;
const int INF = 10000000;
int sx, sy, gx, gy;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
/* 各点までの距離を格納 */
int d[510][510];

int bfs(){
    queue<P> que;

    rep(i,R){
        rep(j, C){
            d[i][j] = INF;
        }
    }

    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while(que.size()){
        P p = que.front();
        que.pop();

        /* if(p.first == gx && p.second == gy) break; */

        for(int dir = 0; dir < 4; dir++){
            int nx = p.first + dx[dir];
            int ny = p.second + dy[dir];
            /*  */
            if(0 <= nx && 0 <= ny && nx < R && ny < C && maze[nx][ny] != '#' && d[nx][ny] == INF){
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gy][gx];
}

/* void clear_seen(){
    rep(i, 15){
        rep(j, 15){
            seen[i][j] = false;
        }
    }
} */

signed main() {
    bool isOk = false;
    cin >> R >> C;
    sx = 0, sy = 0, gx = C-1, gy = R-1;

    maze.resize(R);
    rep(i, R){
        cin >> maze[i];
    }

    int brack = 0;
    rep(i, R){
        rep(j, C){
            if(maze[i][j] == '#') brack++;
        }
    }

    int route = bfs() + 1;
    if(route == INF + 1){
        cout << -1 << endl;
        return 0;
    }

    cout << R * C - route - brack << endl;
    return 0;
}