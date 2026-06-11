#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  string s[n];
  for (int i=0; i<n; i++) cin>>s[i];

  map<int, int> x[26], y[26];
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      int k = s[i][j] - 'a';
      ++x[k][j];
      ++y[k][i];
    }
  }
  set<int> offsets;
  bool first = true;
  for (int i=0; i<26; i++) {
    if (x[i].size() == 0) {
      continue;
    }
    set<int> tmp;
    for (int offset=0; offset<n; ++offset) {
      bool ok = true;
      for (auto e: x[i]) {
        int k = e.first;
        int v = e.second;
        if (y[i][(k + offset) % n] != v) {
          ok = false;
          break;
        }
      }
      if (ok) {
        tmp.insert(offset);
      }
    }
    if (first) {
      offsets = tmp;
      first = false;
    } else {
      set<int> intersect;
      set_intersection(offsets.begin(), offsets.end(), tmp.begin(), tmp.end(), inserter(intersect, intersect.begin()));
      offsets = intersect;
    }
  }
  cout<<n*offsets.size()<<endl;
}