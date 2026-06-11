#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll h, w;
  cin >> h >> w;
  vector < string > s(h);
  for(int i = 0; i < h; i++) cin >> s[i];
  vector < vector < ll > > d(h, vector < ll > (w, 1e18));
  queue < pair < ll, ll > > q;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(s[i][j] == '#'){
        d[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  ll mx = 0;
  vector < ll > dx = {1, 0, -1, 0};
  vector < ll > dy = {0, -1, 0, 1};
  while(!q.empty()){
    int x = q.front().first, y = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++){
      int x1 = x + dx[i], y1 = y + dy[i];
      if(x1 >= 0 && x1 < h && y1 >= 0 && y1 < w && s[x1][y1] == '.'){
        if(d[x1][y1] > d[x][y] + 1){
          d[x1][y1] = d[x][y] + 1;
          mx = max(mx, d[x1][y1]);
          q.push({x1, y1});
        }
      }
    }
  }

  cout << mx << endl;
}
