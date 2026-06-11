#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  vector<vector<int>> c(3, vector<int>(3));
  rep(i, 3) cin >> c.at(i).at(0) >> c.at(i).at(1) >> c.at(i).at(2);

  vector<int> x(3);
  vector<int> y(3);
  rep(i, 3) y.at(i) = c.at(0).at(i) - x.at(0);
  rep(i, 3) x.at(i) = c.at(i).at(0) - y.at(0);
  bool correct = true;
  rep(i, 3) {
    rep(j, 3) {
      if (c.at(i).at(j) != x.at(i) + y.at(j)) correct = false;
    }
  }

  if (correct) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}