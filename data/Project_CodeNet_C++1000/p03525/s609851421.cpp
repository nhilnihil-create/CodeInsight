#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  map<int, int> m_d;
  ++m_d[0];
  for (int i=0; i<n; i++) {
    int di;
    cin>>di;
    ++m_d[di];
  }
  vector<int> d1, d2;
  for (auto x: m_d) {
    if (x.second > 2) {
      cout<<0<<endl;
      return 0;
    } else if (x.second == 2) {
      d2.push_back(x.first);
      d2.push_back(24 - x.first);
    } else {
      d1.push_back(x.first);
    }
  }
  int ans = 0;
  int len1 = d1.size();
  int len2 = d2.size();
  int mask = 1 << len1;
  int max_s = 0;
  for (int i=0; i<mask; i++) {
    int t[len1+len2];
    for (int j=0; j<len1; j++) {
      if ((i >> j) & 1) {
        t[j] = d1[j];
      } else {
        t[j] = 24 - d1[j];
      }
    }
    for (int j=0; j<len2; j++) {
      t[j+len1] = d2[j];
    }
    int min_d = 24;
    for (int j=0; j<len1+len2; j++) {
      for (int k=0; k<len1+len2; k++) {
        if (j == k) {
          continue;
        }
        min_d = min(min(abs(t[k]-t[j]), 24-abs(t[k]-t[j])), min_d);
      }
    }
    max_s = max(min_d, max_s);
  }
  cout<<max_s<<endl;
}