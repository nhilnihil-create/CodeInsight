#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n;
  cin>>h>>w>>n;
  set<int> xs[w];
  for (int i=0; i<n; i++) {
    int x, y;
    cin>>x>>y;
    --y;
    --x;
    xs[y].insert(x);
  }
  for (int i=0; i<w; i++) {
    xs[i].insert(h);
  }
  if (h == 1 || (w > 1 && xs[1].find(0) != xs[1].end())) {
    cout<<1<<endl;
    return 0;
  }
  int ans = 1e6;
  int cur_w = 0;
  for (int i=1; i<h; i++) {
    if (xs[cur_w].find(i) != xs[cur_w].end()) {
      ans = min(i, ans);
      break;
    }
    auto it = xs[cur_w].upper_bound(i);
    ans = min(*it, ans);
    if (cur_w < w - 1) {
      if (xs[cur_w+1].find(i) == xs[cur_w+1].end()) {
        ++cur_w;
      }
    }
  }
  cout<<ans<<endl;
}