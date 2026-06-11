#include <bits/stdc++.h>
 
using namespace std;

const int MAXV = 101;
int visited[MAXV][MAXV], dist[MAXV][MAXV];
pair<int, int> parent[MAXV][MAXV];

const int offset[4][2] = {
    { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }
};



int grid[MAXV][MAXV];
int H, W;
int black = 0;

void bfs(int i, int j){
    memset(parent, -1, sizeof(parent));
    memset(dist, 0, sizeof(dist));
    memset(visited, 0, sizeof(visited));
    
    
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = 1, dist[i][j] = 0;
    
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        
        for (int k = 0; k < 4; k++) {
            int ii = u.first + offset[k][0], jj = u.second + offset[k][1];
            if (ii < 0 || jj < 0 || ii >= H || jj >= W) {
                continue;
            }
            if (!visited[ii][jj] && grid[ii][jj] == 1) {
                visited[ii][jj] = 1;
                parent[ii][jj] = make_pair(u.first, u.second);
                dist[ii][jj] = dist[u.first][u.second] + 1;
                q.push(make_pair(ii, jj));
            }
        }
    }
}



int main(int argc, char *argv[])
{
    
 
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    memset(grid, -1, sizeof(grid));
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
                black++;
            }
        }
    }
    
    bfs(0, 0);
    if (!dist[H - 1][W - 1]) {
        cout << "-1" << endl;
        return 0;
    }
    
    
    cout << H * W - dist[H - 1][W - 1] - 1 - black << endl;
    
    return 0;
}
