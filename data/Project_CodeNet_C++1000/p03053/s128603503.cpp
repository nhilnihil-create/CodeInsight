#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
  int h,w;
  string map[1000];

  cin >> h >> w;
  for (int i = 0; i < h; i++) cin >> map[i];

  queue<pair<int,int>> todo;
  vector<vector<int>> seen(h,vector<int>(w,-1));
  //初期の黒マスをすべてtodoリストのキューにプッシュ
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if(map[i][j] == '#'){
        todo.push(make_pair(i,j));
        seen[i][j] = 0;
      }
    }
  }


  int dx[] = {0,0,1,-1};
  int dy[] = {1,-1,0,0};

  while(!todo.empty()){
    pair<int,int> pos = todo.front();
    todo.pop();
    int x = pos.first;
    int y = pos.second;
    for (int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
      if(map[nx][ny] == '#') continue;
      if(seen[nx][ny] == -1){
        todo.push(make_pair(nx,ny));
        map[nx][ny] = '#';
        seen[nx][ny] = seen[x][y] + 1;
      }
    }
  }

  // sort(seen.begin(), seen.end());

  // cout << seen[h-1][w-1] << endl;

  int currentmax = seen[0][0];
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
        if(seen[i][j] > currentmax) currentmax = seen[i][j];
    }
  }
  cout << currentmax << endl;

}