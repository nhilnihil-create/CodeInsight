#include<bits/stdc++.h>

using namespace std;

#define P pair<int,int>

const int nmax = 50;
char maze[nmax][nmax];
int cost[nmax][nmax];

void bfs(int H,int W){
    queue<P> q;
    P pos;
    int n_x,n_y,x,y;
    int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    q.push(P(0,0));
    cost[0][0] = 1;
    while(!q.empty()){
        pos = q.front();
        q.pop();
        n_x = pos.first;
        n_y = pos.second;
        if(n_x == W - 1 && n_y == H - 1){
            return;
        }

        for(int i = 0;i < 4;i++){
            x = n_x + direction[i][0];
            y = n_y + direction[i][1];
            if(x < 0 || W <= x || y < 0 || H <= y) continue;
            if(cost[y][x] < INT_MAX) continue;
            if(maze[y][x] == '#') continue;
            cost[y][x] = min(cost[y][x],cost[n_y][n_x] + 1);
            q.push(P(x,y));
        }
    }
}

int main(){
    int H,W,b,w;
    char c;

    cin >> H >> W;

    b = w = 0;
    for(int y = 0;y < H;y++){
        for(int x = 0;x < W;x++){
            cin >> c;
            maze[y][x] = c;
            cost[y][x] = INT_MAX;
            if(c == '.'){
                w++;
            }else{
                b++;
            }
        }
    }

    bfs(H,W);

    if(cost[H - 1][W - 1] == INT_MAX){
        cout << "-1" << endl;
        return 0;
    }
    cout << w - cost[H - 1][W - 1] << endl;

}