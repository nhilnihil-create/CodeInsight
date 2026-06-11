#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  
  vector<P> cell(h*w);
  rep(i, h) rep(j, w) {
    int ci = i*w + j;
    if (i % 2 == 0) cell[ci] = make_pair(i, j);
    else cell[ci] = make_pair(i, w-j-1);
  }

  vector<pair<P, P>> ans;
  rep(ci, h*w-1) {
    int y = cell[ci].first;
    int x = cell[ci].second;
    if (a[y][x] % 2 == 0) continue;
    a[y][x]--;
    int yp = cell[ci+1].first;
    int xp = cell[ci+1].second;
    a[yp][xp]++;
    ans.push_back(make_pair(make_pair(y, x), make_pair(yp, xp)));
  }

  int n = ans.size();
  printf("%d\n", n);
  rep(i, n) {
    int y = ans[i].first.first + 1;
    int x = ans[i].first.second + 1;
    int yp = ans[i].second.first + 1;
    int xp = ans[i].second.second + 1;
    printf("%d %d %d %d\n", y, x, yp, xp);
  }
  return 0;
}