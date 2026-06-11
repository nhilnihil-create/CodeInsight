#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  int size;
  int d;
  for (int i = 0; i < n; i++) {
    cin >> size;
    for (int j = 0; j < size; j++) {
      cin >> d;
      a.at(i).push_back(d);
    }
  }
  int sum;
  int res = 0;
  for (int k = 1; k <= m; k++) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int)a.at(i).size(); j++) {
        if (a.at(i).at(j) == k) {
          sum++;
        }
      }
    }
    if (sum == n) {
      res++;
    }
  }
  cout << res << endl;
}
