#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<int>> m(h, vector<int>(w, -1));
  int cnt = 0;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      char s;
      cin >> s;
      if(s=='#') m[i][j] = 0;
      else cnt++;
    }
  }
  cnt--;
  queue<P> que;
  m[0][0] = 0;
  que.push(make_pair(0,0));
  while(!que.empty()){
    P p = que.front();
    que.pop();
    int x = p.first, y = p.second;
    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx<0 || nx>=h || ny<0 || ny >=w) continue;
      if(m[nx][ny] != -1) continue;
      m[nx][ny] = m[x][y] + 1;
      que.push(make_pair(nx, ny));
    }
  }
  if(m[h-1][w-1] == -1){
    cout << -1 << endl;
    return 0;
  }
  int ans = cnt - m[h-1][w-1];
  cout << ans << endl;
  return 0;
}
