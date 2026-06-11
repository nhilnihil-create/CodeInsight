#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(m, vector<int>(0));
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    for(int j=0; j<x; j++) {
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