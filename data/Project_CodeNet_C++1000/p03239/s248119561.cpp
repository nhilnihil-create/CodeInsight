#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  int res = 10000;
  int cm = 10000;
  vector<pair<int, int>> root(n);
  for (int i = 0; i < n; i++) {
    cin >> root.at(i).first;
    cin >> root.at(i).second;
  }
  for (int i = 0; i < n; i++) {
    if (root.at(i).second > t) {
      continue;
    }
    else {
      if (root.at(i).first <= cm) {
        cm = root.at(i).first;
        res = root.at(i).second;
      }
    }
  }
  if (res == 10000) {
    cout << "TLE" << endl;
  }
  else {
    cout << cm << endl;
  }
}


