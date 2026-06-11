#include<iostream>
#include<queue>
using namespace std;

typedef pair<int, int> P;
const int INF = 1000000;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
    int H, W;
    char field[1000][1000];
    int dist[1000][1000];
    int max_dist = 0;
    cin >> H >> W;

    queue<P> que;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> field[i][j];
            if(field[i][j] == '#'){
                que.push(P(i, j));
                dist[i][j] = 0;
            }else{
                dist[i][j] = INF;
            }
        }
    }

    while(que.size()){
        P p = que.front();
        que.pop();

        for(int i=0; i<4; i++){
            int nx = p.first + dx[i], ny = p.second + dy[i];

            if(0 <= nx && nx < H && 0 <= ny && ny < W && dist[nx][ny] == INF){
                dist[nx][ny] = dist[p.first][p.second] + 1;
                que.push(P(nx, ny));
                max_dist = max(max_dist, dist[nx][ny]);
            }
        }
    }

    cout << max_dist << endl;
    return 0;
}
