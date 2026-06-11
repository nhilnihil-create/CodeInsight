#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;


int dp[60][60];
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

int main() {
  int h, w;
  cin >> h >> w;
  char tab[60][60];
  int m = 0;//'.'の数
  rep(i,h) {
    rep(j,w) {
      cin >> tab[i][j];
      if(tab[i][j]=='.') m++;
    }
  }
  rep(i,h) {
    rep(j,w) dp[i][j] = INF;
  }
  dp[0][0] = 1;
  queue<P> que;
  que.push({0,0});
  while(!que.empty()) {
    P a = que.front();
    que.pop();
    rep(i,4) {
      int y = a.first+dy[i];
      int x = a.second+dx[i];
      if(y<0||y>=h||x<0||x>=w) continue;
      if(tab[y][x]=='#') continue;
      if(dp[y][x]!=INF) continue;
      dp[y][x] = dp[a.first][a.second]+1;
      que.push({y,x});
    }
  }
  int ans = m - dp[h-1][w-1];
  if(ans<0) ans = -1;
  cout << ans << endl;
  return 0;
}