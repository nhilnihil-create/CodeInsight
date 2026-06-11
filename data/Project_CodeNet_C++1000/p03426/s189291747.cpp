#include <bits/stdc++.h>
using namespace std;

vector<int> cost[90001];
int main() {
  int h, w, d;
  cin>>h>>w>>d;
  pair<int, int> p[h*w+1];
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      int a;
      cin>>a;
      p[a] = make_pair(i, j);
    }
  }
  for (int i=1; i<=d; i++) {
    cost[i].push_back(0);
    for (int j=i+d; j<=w*h; j+=d) {
      if (j - d >= 1) {
        cost[i].push_back(cost[i].back()
          + abs(p[j].first - p[j-d].first)
          + abs(p[j].second - p[j-d].second));
      }
    }
  }
  int q;
  cin>>q;
  for (int _=0; _<q; _++) {
    int l, r;
    cin>>l>>r;
    int mod = l % d;
    if (mod == 0) {
      mod = d;
      --l;
      --r;
    }
    cout<<cost[mod][r/d] - cost[mod][l/d]<<endl;
  }
}