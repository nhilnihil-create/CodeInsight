#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m; cin >> n >> m;
  vector<vector<int>> a;
  for (int i=0; i<n; i++) {
    int k, t; cin >> k;
    vector<int> tmp;
    for (int j=0; j<k; j++) {
      cin >> t;
      tmp.push_back(t);
    }
    a.push_back(tmp);
  }
  
  int cnt = 0;;
  for (int k=1; k<m+1; k++) {
    int flag = 0;
    for (int i=0; i<n; i++) {
      for (int j=0; j<a[i].size(); j++) {
        if (a[i][j] == k) flag++;
      }
    }
    if (flag == n) cnt++;
  }
  cout << cnt << endl;
  return 0;
}