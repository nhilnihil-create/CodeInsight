#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG

signed main() {
  int H, W; cin >> H >> W;
  vector<vector<bool>> a(H, vector<bool>(W, false));
  rep(i, H) rep(j, W) {
    int n; cin >> n;
    if(n%2 == 0) a[i][j] = true;
  }
  vector<vector<int>> ans(0);
  
  rep(i, H) {
    if(i%2 == 0) {
      rep(j, W) {
        if(!a[i][j]) {
          if(j < W-1) {
            ans.push_back({i, j, i, j+1});
            a[i][j+1] = !(a[i][j+1]);
          } else {
            if(i == H-1) break;
            ans.push_back({i, j, i+1, j});
            a[i+1][j] = !a[i+1][j];
          }
        }
      }
    } else {
      rep(j, W) {
        if(!a[i][W-1-j]) {
          if(j < W-1) {
            ans.push_back({i, W-1-j, i, W-1-j-1});
            a[i][W-1-j-1] = !a[i][W-1-j-1];
          } else {
            if(i == H-1) break;
            ans.push_back({i, W-1-j, i+1, W-1-j});
            a[i+1][W-1-j] = !a[i+1][W-1-j];
          }
        }
      }
    }
  }
  
  cout << ans.size() << endl;
  rep(i, ans.size()) {
    rep(j, 3) cout << ans[i][j]+1 << " ";
    cout << ans[i][3]+1 << endl;
  }
}
