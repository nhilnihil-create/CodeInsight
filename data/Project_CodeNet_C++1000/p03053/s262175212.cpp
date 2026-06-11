#include <iostream>
#include <queue>
using namespace std;

int H,W;
char A[1007][1007];

//
// BFS(幅優先探索)
//
int D[1007][1007];
int vx[4] = {0,-1,0,1};
int vy[4] = {1,0,-1,0};

int bfs(){
    int ans = 0;
    queue<pair <int,int> > Q;

    // 初回で黒の場合はQに突っ込む
    for(int y = 1; y< H+1;y++){
        for(int x = 1;x < W+1;x++){
            if(A[x][y] == '#'){
                D[x][y] = 0;
                Q.push(make_pair(x,y));
            }
        }
    }

    pair <int,int> p;

    while(!Q.empty()){
        p = Q.front(); Q.pop();

        for(int i = 0;i < 4;i++){
            int nx = p.first  + vy[i];
            int ny = p.second + vx[i];

            if(nx >= 1 && nx <= W && ny >= 1 && ny <= H && A[nx][ny] == '.'){
                Q.push(make_pair(nx,ny));
                D[nx][ny] = D[p.first][p.second] + 1;
                A[nx][ny] = '#';
                if(D[p.first][p.second] + 1 > ans){
                    ans = D[p.first][p.second] + 1;
                }
            }
        }

    }

    return ans;
}


int main(){
    cin >> H >> W;
    for(int y = 1; y< H+1;y++){
        for(int x = 1;x < W+1;x++){
            cin >> A[x][y];
        }
    }

    int ans = bfs();
    cout << ans << endl;
}