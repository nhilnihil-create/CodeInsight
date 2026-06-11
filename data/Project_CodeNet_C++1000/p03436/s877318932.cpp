#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

const int MOD = 1e9+7;
const int INF = 1001001001;

int H, W;
char maze[50][50];

int bfs(int sx, int sy, int gx, int gy){
    int dist[50][50];
    fill(dist[0], dist[50], INF);
    dist[sx][sy] = 1;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    deque<pii> q;
    q.emplace_back(sx, sy);
    while (!q.empty()){
        pii xy = q.front();
        int x = xy.first;
        int y = xy.second;
        q.pop_front();
        if (x == gx && y == gy){
            return dist[x][y];
        }
        rep(i, 0, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && dist[nx][ny] == INF && maze[nx][ny] == '.'){
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace_back(nx, ny);
            }
        }
    }
    return -1;
}

int main(){
    cin >> H >> W;
    int cnt = 0;
    rep(x, 0, H){
        rep(y, 0, W){
            cin >> maze[x][y];
            if (maze[x][y] == '.'){
                cnt++;
            }
        }
    }
    int num = bfs(0, 0, H-1, W-1);
    int ans = (num != -1) ? cnt-num : -1;
    cout << ans << endl;
}