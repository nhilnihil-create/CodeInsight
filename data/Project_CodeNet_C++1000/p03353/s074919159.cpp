#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int k;
  cin>>k;
  int n = s.length();
  for (char c='a'; c<='z'; c++) {
    set<string> ss;
    for (int i=0; i<n; i++) {
      if (s[i] != c) {
        continue;
      }
      for (int j=1; j<=k; j++) {
        ss.insert(s.substr(i, j));
      }
    }
    if (ss.size() < k) {
      k -= ss.size();
    } else {
      vector<string> v(ss.begin(), ss.end());
      cout<<v[k-1]<<endl;
      return 0;
    }
  }
}