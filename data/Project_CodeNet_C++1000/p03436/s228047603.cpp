#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int INF = 1000000;

char maze[100][100];
int d[100][100];
int H, W;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(){
    queue<pair<int, int> > Q;
    Q.push(make_pair(1, 1));
    d[1][1] = 0;

    while(Q.size()){
        pair<int, int> p = Q.front(); Q.pop();
        if(p.first == H && p.second == W) break;

        for (int i = 0; i < 4; i++){
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if(nx >=1 && nx <= H && ny >= 1 && ny <= W && maze[nx][ny] == '.' && d[nx][ny] == INF){
                Q.push(make_pair(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[H][W];
}

int main() {
    cin >> H >> W;
    int b = 0;
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            cin >> maze[i][j];
            if (maze[i][j] != '.') b++;
            d[i][j] = INF;
        }
    }

    int dis = bfs();
    if (dis == INF){
        cout << -1 << endl;
    } else {
        cout << H*W - b - dis - 1 << endl;
    }

    return 0;
}