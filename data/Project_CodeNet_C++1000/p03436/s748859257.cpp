#include <bits/stdc++.h>
#include <cstring>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    int h, w; cin >> h >> w;
    V<string> b(h);
    for(int i = 0; i < h; i++) cin >> b[i];

    int sum = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(b[i][j] == '.') sum++;
        }
    }

    int dis[h + 1][w + 1];
    memset(dis, -1, sizeof(dis));
    dis[0][0] = 1;

    int gy = h - 1, gx = w - 1;
    queue<P<int, int> > que;
    que.push({0, 0});

    while(!que.empty()){
        auto p = que.front();
        que.pop();

        int y = p.first;
        int x = p.second;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
            if(b[ny][nx] == '#') continue;
            if(dis[ny][nx] != -1) continue;
            if(ny == gy && nx == gx){
                dis[gy][gx] = dis[y][x] + 1;
                break;
            }
            dis[ny][nx] = dis[y][x] + 1;
            que.push({ny, nx});
        }
    }

    if(dis[gy][gx] == -1) cout << -1 << endl;
    else cout << sum - dis[gy][gx] << endl;
}
