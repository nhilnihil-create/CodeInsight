#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(m, vector<int>(0));
  while(true) {
    int x;
    cin >> x;
    if(cin.eof()) break;
    for(int i=0; i<x; i++) {
      int y;
      cin >> y;
      v[y-1].push_back(334);
    }
  }
  int count = 0;
  for(int i=0; i<m; i++) if(v[i].size() == n) count++;
  cout << count << endl;
  return 0;
}