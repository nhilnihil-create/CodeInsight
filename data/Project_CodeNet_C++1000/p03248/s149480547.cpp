#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n = s.length();
  if (s[0] == '0' || s[n-1] == '1' || s[n-2] == '0') {
    cout<<-1<<endl;
    return 0;
  }
  for (int i=1; i<(n-1)/2; i++) {
    if (s[i] != s[n-i-2]) {
      cout<<-1<<endl;
      return 0;
    }
  }
  vector<int> g[n];
  g[0].push_back(1);
  int i = 1;
  while (i < n - 1) {
    int j = i;
    while (i < n && s[i] == '0') {
      ++i;
      g[j].push_back(i);
    }
    ++i;
    g[j].push_back(i);
  }
  for (int i=0; i<n; i++) {
    for (int to: g[i]) {
      cout<<i+1<<" "<<to+1<<endl;
    }
  }
}