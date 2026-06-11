#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int H,W;
  cin >> H >> W;
  int a[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }
  vector<pair<P,P>> ans;
  for (int i = 0; i < H - 1; i++) {
    for (int j = 0; j < W; j++) {
      if (a[i][j] % 2 == 1) {
        ans.push_back(make_pair(make_pair(i,j),make_pair(i+1,j)));
        a[i][j] -= 1;
        a[i+1][j] += 1;
      }
    }
  }
  for (int i = 0; i < W - 1; i++) {
    if (a[H-1][i] % 2 == 1) {
      ans.push_back(make_pair(make_pair(H-1,i),make_pair(H-1,i+1)));
      a[H-1][i] -= 1;
      a[H-1][i+1] += 1;
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first.first + 1 << " " << ans[i].first.second + 1 << " " << ans[i].second.first + 1 << " " << ans[i].second.second + 1 << endl;
  }
  return 0;
}