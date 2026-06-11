#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

vector<int> si = {-1, 0, 1, 0};
vector<int> sj = {0, -1, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<vector<int>> dist(h,vector<int>(w,M));
  queue<pair<int,int>> q;
  q.push(make_pair(0, 0));
  dist[0][0] = 0;
  while(!q.empty()){
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    rep(x, 4){
      int ni = i + si[x];
      int nj = j + sj[x];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      if (dist[ni][nj] != M) continue;
      dist[ni][nj] = dist[i][j] + 1;
      q.push(make_pair(ni,nj));
    }
  }

  if (dist[h-1][w-1] == M) {
    cout << -1 << endl;
    return 0;
  }

  int black = 0;
  rep(i,h) rep(j,w) if(s[i][j] == '#') black++;
  cout << h*w - black - dist[h-1][w-1] - 1 << endl;
  return 0;
}
