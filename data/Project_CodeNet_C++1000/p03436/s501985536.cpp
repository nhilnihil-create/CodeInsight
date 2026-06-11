#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int INF=1e9;

int R, C;
vector<vector<char>> maze;  // 迷路の内容を保存する配列
vector<vector<int>> dist;   // 距離を記録しておく配列
int sx, sy, gx, gy;  //sx,syはスタート、gx,gyはゴール、（1-index）

int main() {
    cin >> R >> C;
    sy=0;  
    sx=0;
    gy=R-1;
    gx=C-1;
    ll white=0;

    dist.assign(R, vector<int>(C, INF));   // 初期化
    maze.assign(R, vector<char>(C, '.'));  // 初期化

    rep(i,R) {
      rep(j,C){
        cin >> maze[i][j];
        if(maze[i][j]=='.')white++;
      }
    }

    queue<pair<int, int>> que;
    que.emplace(make_pair(sy, sx));  // sから探索する
    dist[sy][sx] = 0;
    while (que.size() != 0) {              // キューの要素がなくなったら終了
        pair<int, int> now = que.front();  // 現在の状態
        que.pop();

        if (now.first == gy && now.second == gx) {  // 目的地にたどり着いたので終了
            break;
        }

        int dy[4] = {0, 0, 1, -1};  // dx,dy は次の探索場所への距離を表す（４方向分）
        int dx[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int ny = now.first + dy[i];                            // 次の探索場所の行番号
            int nx = now.second + dx[i];                           // 次の探索場所の列番号
            if (ny < 0 || R <= ny || nx < 0 || C <= nx) continue;  // 迷路の外に出るならスルー
            if (maze[ny][nx] == '#') continue;                     // 障害物があればスルー
            if (dist[ny][nx] != INF) continue;                     //探索済みならスルー
            que.push(make_pair(ny, nx));
            dist[ny][nx] =dist[now.first][now.second] + 1;
        }
    }

  if(dist[gy][gx]==INF){cout << -1 << endl;}else{cout << white-dist[gy][gx]-1 << endl;}

}