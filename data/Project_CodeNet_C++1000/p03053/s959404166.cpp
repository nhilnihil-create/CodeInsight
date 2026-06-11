#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

const int MOD = 1e9+7;
const int INF = 1001001001;
int dist[1000][1000];
char maze[1000][1000];

int main(){
    int H, W;
    cin >> H >> W;
    deque<pii> q;
    rep(i, 0, H){
        rep(j, 0, W){
            char st;
            cin >> st;
            maze[i][j] = st;
            if (st == '#'){
                q.emplace_back(i, j);
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = INF;
            }
        }
    }
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int ans = 0;
    while (!q.empty()){
        pii xy = q.front();
        int x = xy.first;
        int y = xy.second;
        q.pop_front();
        rep(i, 0, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && maze[nx][ny] == '.' && dist[nx][ny] == INF){
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace_back(nx, ny);
                ans = max(ans, dist[nx][ny]);
            }
        }
    }
    cout << ans << endl;
}