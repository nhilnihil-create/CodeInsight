#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  bool ok = true;
  vector<int> t(N + 1), x(N + 1), y(N + 1);
  t.at(0) = 0;
  x.at(0) = 0;
  y.at(0) = 0;
  for (int i = 1; i < (N + 1); i++) {
    cin >> t.at(i) >> x.at(i) >> y.at(i);
    if (abs(abs(x.at(i) - x.at(i - 1)) + abs(y.at(i) - y.at(i - 1))) > (t.at(i) - t.at(i - 1))) {
      ok = false;
      break;
    }
    if (((t.at(i) - t.at(i - 1)) - abs(abs(x.at(i) - x.at(i - 1)) + abs(y.at(i) - y.at(i - 1)))) % 2 == 1) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}