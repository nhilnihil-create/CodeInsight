#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

vector<int> dx{1, 0, -1, 0};
vector<int> dy{0, -1, 0, 1};
int main(){
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  int count = 0;
  rep(i, h){
    cin >> s[i];
    rep(j, w) if(s[i][j] == '.') count++;
  }
  
  vector<vector<int>> dist(h, vector<int>(w, -1));
  queue<pair<int, int>> que;
  dist[0][0] = 0;
  que.push(make_pair(0, 0));
  int ans = -1;
  bool flag = false;
  while(!que.empty()){
    auto pos = que.front();
    que.pop();
    int ph = pos.first;
    int pw = pos.second;
    rep(i, 4){
      int nh = ph + dx[i];
      int nw = pw + dy[i];
      if (nh < 0 || nw < 0 || nh >= h || nw >= w) continue;
      if (dist[nh][nw] != -1 || s[nh][nw] == '#') continue;
      dist[nh][nw] = dist[ph][pw] + 1;
      que.push(make_pair(nh, nw));
      if (nh == h-1 && nw == w-1){
        ans = count - (dist[nh][nw] + 1);
        flag = true;
        break;
      }
    }
    if(flag) break;
  }
  cout << ans << endl;
  
  return 0;
}