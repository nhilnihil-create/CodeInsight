#include <bits/stdc++.h>
using namespace std;

int main () {
  string s, t; cin >> s >> t;
  map<char,int> ms, mt;
  int idx = 1;
  vector<int> ss(s.size()), ts(s.size());
  for (int i = 0; i < s.size(); ++i) {
    if (ms.count(s[i]) == 0) {
      ms[s[i]] = idx++;
    }
    ss[i] = ms[s[i]];
  }
  idx = 1;
  for (int i = 0; i < s.size(); ++i) {
    if (mt.count(t[i]) == 0) {
      mt[t[i]] = idx++;
    }
    ts[i] = mt[t[i]];
  }
  
  bool ok = 1;
  for (int i = 0; i < s.size(); ++i) {
    if (ss[i] != ts[i]) ok = 0;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}