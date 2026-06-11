#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  map<int, int> md;
  ++md[0];
  for (int i=0; i<n; i++) {
    int di;
    cin>>di;
    ++md[di];
  }
  vector<int> d1, d2;
  for (auto e: md) {
    int v = e.second;
    if (v == 1) {
      if (e.first == 0) {
        d2.push_back(e.first);
      } else {
        d1.push_back(e.first);
      }
    } else if (v == 2) {
      d2.push_back(e.first);
      d2.push_back(24 - e.first);
    } else {
      cout<<0<<endl;
      return 0;
    }
  }
  int size = d1.size();
  int ans = 0;
  for (int state=0; state<(1<<size); state++) {
    vector<int> v;
    for (int i=0; i<size; i++) {
      if ((state>>i) & 1) {
        v.push_back(24 - d1[i]);
      } else {
        v.push_back(d1[i]);
      }
    }
    for (int di: d2) {
      v.push_back(di);
    }
    sort(v.begin(), v.end());
    int s = 12;
    for (int i=0; i<v.size(); i++) {
      int x = abs(v[(i+1)%v.size()] - v[i]);
      s = min(min(x, 24 - x), s);
    }
    ans = max(s, ans);
  }
  cout<<ans<<endl;
}