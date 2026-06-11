#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,w;
  int ans = 0;
  cin >> h >> w;
  vector<string>data(h);
  vector<vector<int>>cnt(h,vector<int>(w,0));
  rep(i,0,h) cin >> data[i];
  queue<P>que;
  rep(i,0,h) rep(j,0,w) if(data[i][j] == '#') que.push(P(i,j));
  while(!que.empty()){
    int x,y;
    x = que.front().first;
    y = que.front().second;
    que.pop();
    if(x > 0) if(data[x-1][y] == '.'){
      data[x-1][y] = '#';
      que.push(P(x-1,y));
      cnt[x-1][y] = cnt[x][y]+1;
      ans = cnt[x-1][y];
    }
    if(x < h-1) if(data[x+1][y] == '.'){
      data[x+1][y] = '#';
      que.push(P(x+1,y));
      cnt[x+1][y] = cnt[x][y]+1;
      ans = cnt[x+1][y];
    }
    if(y > 0) if(data[x][y-1] == '.'){
      data[x][y-1] = '#';
      que.push(P(x,y-1));
      cnt[x][y-1] = cnt[x][y]+1;
      ans = cnt[x][y-1];
    }
    if(y < w-1) if(data[x][y+1] == '.'){
      data[x][y+1] = '#';
      que.push(P(x,y+1));
      cnt[x][y+1] = cnt[x][y]+1;
      ans = cnt[x][y+1];
    }
  }
  cout << ans << endl;
}