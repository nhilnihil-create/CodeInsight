#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<utility>

using std::cin;
using std::cout;
using std::vector;
using std::queue;
using std::string;
using std::pair;
using std::make_pair;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int h, w;
char s[100][100];
int bfs(int sx, int sy, int gx, int gy) {
    int dist[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dist[i][j]=-1;
        }
    }
    dist[0][0] = 0;

    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int next_y = now.second + dy[i];
            int next_x = now.first + dx[i];
            if(0 <= next_y && next_y < h && 0 <= next_x && next_x < w && s[next_y][next_x] != '#') {
                if(dist[next_y][next_x]==-1 || dist[next_y][next_x] > dist[now.second][now.first] + 1) {
                    q.push(make_pair(next_x,next_y));
                    dist[next_y][next_x] = dist[now.second][now.first] + 1;
                }
            }
        }
    }
    return dist[h-1][w-1];
}

int main() {
    cin >> h >> w;
    string buf;
    for(int i=0;i<h;i++) {
        scanf("%s", s[i]);
    }

    int cnt = 0;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++){
            if(s[i][j]=='.'){
                cnt++;
            }
        }
    }
    int res = bfs(0, 0, h-1, w-1);
    if(res==-1){
        printf("-1");
    }else{
        printf("%d\n", cnt-1-res);
    }
}

