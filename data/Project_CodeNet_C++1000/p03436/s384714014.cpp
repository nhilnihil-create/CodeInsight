#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char *argv[])
{
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  int H,W,x,y;
  char tmp;
  int w_count = 0;
  queue<int> queue_x,queue_y;
  cin >> H >> W;
  vector<vector<int> > c(H,vector<int>(W));
  vector<vector<int> > visited(H,vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> tmp;
      if(tmp == '#')
        c.at(i).at(j) = 0;
      else{
        c.at(i).at(j) = 1;
        w_count++;
      }
      visited.at(i).at(j) = 0;
    }
  }
  //迷路の確認
  //for (int i = 0; i < H; i++) {
  //  for (int j = 0; j < W; j++) {
  //    cout << c.at(i).at(j);
  //  }
  //  cout << endl;
  //}
  queue_x.push(0);
  queue_y.push(0);
  visited.at(0).at(0) = 1;
  while(!queue_x.empty() && !queue_y.empty()){
    x = queue_x.front();
    y = queue_y.front();
    //cout << "x: " << x << " y: " << y << endl;
    queue_x.pop();queue_y.pop();
    for (int n = 0; n < 4; n++) {
      if(x+dx[n] >= 0 && x+dx[n] < H && y+dy[n] >= 0 && y+dy[n] < W &&
          c.at(x+dx[n]).at(y+dy[n]) == 1 &&
          visited.at(x+dx[n]).at(y+dy[n]) == 0){
        queue_x.push(x+dx[n]);
        queue_y.push(y+dy[n]);
        visited.at(x+dx[n]).at(y+dy[n]) = visited.at(x).at(y) + 1;
      }
    }
  }
  //for (int i = 0; i < H; i++) {
  //  for (int j = 0; j < W; j++) {
  //    cout << visited.at(i).at(j);
  //  }
  //  cout << endl;
  //}
  if(visited.at(H-1).at(W-1) == 0)
    cout << -1 << endl;
  else
    cout << w_count - visited.at(H-1).at(W-1) << endl;
  return 0;
}
