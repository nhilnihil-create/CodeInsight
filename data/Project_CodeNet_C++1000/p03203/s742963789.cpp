#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()
#define let auto const

int main() {
  i64 H, W, N;
  cin >> H >> W >> N;
  vector<vector<i64>> Xs(H + 1);
  vector<vector<i64>> Ys(W + 1);
  for(int i = 0;i < N;i++) {
    i64 x, y;
    cin >> x >> y;
    Xs[x].push_back(y);
    Ys[y].push_back(x);
  }
  for(int i = 1;i <= H;i++) Xs[i].push_back(W + 1);
  for(int i = 1;i <= W;i++) Ys[i].push_back(H + 1);
  for(int i = 1;i <= H;i++) sort(all(Xs[i]));
  for(int i = 1;i <= W;i++) sort(all(Ys[i]));

  i64 h = 1;
  i64 w = 1;
  i64 ending = Ys[1].front();
  while(++h < ending) {
    if(*lower_bound(all(Xs[h]), w) == w + 1) {
    }
    else {
      w++;
      ending = min(ending, *lower_bound(all(Ys[w]), h));
    }
  }

  cout << ending - 1 << endl;
}
