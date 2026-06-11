#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> px = {0, 1, 0, -1};
vector<int> py = {1, 0, -1, 0};

int main() {
  int h,w,numPoints=0,ans=0;
  cin >> h >> w;
  vector<string> a(h);
  for(int i=0; i<h; i++) cin >> a[i];
  vector<vector<bool>> isBlack(h,vector<bool>(w, false));
  queue<pair<int,int>> que;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++) {
      if(a[i][j]=='#') {
        isBlack[i][j] = true;
        que.push({i,j});
        numPoints++;
      }
    }
  }
  while(!que.empty()) {
    vector<pair<int,int>> points;
    int numNewPoints=0;
    for(int i=0; i<numPoints; i++) {
      points.push_back(que.front());
      que.pop();
      for(int j=0; j<4; j++) {
        int nx=points[i].first+px[j];
        int ny=points[i].second+py[j];
        if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
        if(isBlack[nx][ny]) continue;
        isBlack[nx][ny] = true;
        que.push({nx,ny});
        numNewPoints++;
      }
    }
    numPoints=numNewPoints;
    if(!que.empty())ans++;
  }
  cout << ans << endl;
}
