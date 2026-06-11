#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> t(n + 1);
  vector<int> x(n + 1);
  vector<int> y(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> t.at(i) >> x.at(i) >> y.at(i);
  }

  bool canArrive = true;
  for (int i = 0; i < n; i++) {
    int dt = t.at(i + 1) - t.at(i);
    int dist = abs(x.at(i + 1) - x.at(i)) + abs(y.at(i + 1) - y.at(i));
    if (dist > dt) {
      canArrive = false;
      break;
    }
    if (dist % 2 != dt % 2) {
      canArrive = false;
      break;
    }
  }

  if (canArrive) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}