#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  vvi c(3, vi(3));
  rep(i, 3) {
    rep(j, 3) {
      cin >> c[i][j];
    }
  }
  int a, b;
  a = c[0][0] - c[0][1];
  b = c[0][1] - c[0][2];
  bool check = false;
  rep(i, 2) {
    if (c[i+1][0] - c[i+1][1] == a && c[i+1][1] - c[i+1][2] == b) {
      check = true;
    }
    else {
      check = false;
      break;
    }
  }
  if (check) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
