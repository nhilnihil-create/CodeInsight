#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    int h, w;   cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    vector<vector<int>> cost(h, vector<int>(w, -1));
    queue<pair<int, int>> que;

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++){
            cin >> g.at(i).at(j);
            if(g.at(i).at(j)=='#'){
                que.push({i, j}); cost[i][j]=0;
            }
        }


    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    
    while(!que.empty()){
        int x = que.front().first, y = que.front().second;
        que.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0 || ny<0 || h<=nx || w<=ny) continue;
            if(cost[nx][ny]!=-1) continue;
            cost[nx][ny] = cost[x][y] + 1;
            que.push({nx, ny});
        }
    }
    int res=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            res = max(res, cost[i][j]);
        }
    }

    cout << res << endl;
    
}


