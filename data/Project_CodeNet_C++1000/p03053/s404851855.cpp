#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dx[4]={ 0, 1,  0, -1};
int dy[4]={ 1, 0, -1,  0};
using P = pair<int,int>;
int h, w, n;
int sx, sy, gx, gy;
int ans=0;
char c[1000][1000];
queue<P> que;

int main(){
  cin >> h >> w;
  queue<P> que;
  vector<vector<int>> d(w, vector(h, -1));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> c[j][i];
      if(c[j][i] == '#'){
        que.push(P(j,i));
        d[j][i] = 0;
      }
    }
  }

  while(!que.empty()){
    P p = que.front();
    que.pop();
    int px = p.first, py = p.second;
    for(int i=0; i<4; i++){
      int nx = px+dx[i], ny = py+dy[i];
      if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      else{
      	if(c[nx][ny] == '.'){
          c[nx][ny] = '#';
          d[nx][ny] = d[px][py] + 1;
          que.push(P(nx, ny));
        }
      }
    }
  }
  
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(ans < d[j][i]) ans = d[j][i];
    }
  }  
  cout << ans << endl;
}