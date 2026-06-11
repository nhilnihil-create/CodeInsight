#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const double PI=3.1415926535897932;
using namespace std;
typedef long long ll;

vector< vector< int > > grid_bfs(vector<string> &s, char start, const string &wall="#") {
  const int vx[] = {0, 1, 0, -1}, vy[] = {1, 0, -1, 0};
  vector< vector< int > > min_cost(s.size(), vector< int >(s[0].size(), -1));
  queue< pair< int, int > > que;
  for(int i = 0; i < s.size(); i++) {
    for(int j = 0; j < s[i].size(); j++) {
      if(s[i][j] == start) {
        que.emplace(i, j);
        min_cost[i][j] = 0;
      }
    }
  }
  while(!que.empty()) {
    auto p = que.front();
    que.pop();
    for(int i = 0; i < 4; i++) {
      int ny = p.first + vy[i], nx = p.second + vx[i];
      if(nx < 0 || ny < 0 || nx >= s[0].size() || ny >= s.size()) continue;
      if(min_cost[ny][nx] != -1) continue;
      if(wall.find(s[ny][nx]) != string::npos) continue;
      min_cost[ny][nx] = min_cost[p.first][p.second] + 1;
      que.emplace(ny, nx);
    }
  }
  return min_cost;
}

int main(void){
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,h){
        cin>>s[i];
    }
    int c=-1;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='.')c++;
        }
    }
    //string wa="#";
    s[0][0]='s';
    
    vector<vector<int>> mincost;
    mincost=grid_bfs(s,'s');
    if(mincost[h-1][w-1]==-1)cout<<-1<<endl;
    else cout<<c-mincost[h-1][w-1]<<endl;
    //cout<<mincost[h-1][w-1]<<endl;
}