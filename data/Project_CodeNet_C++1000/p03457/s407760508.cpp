#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  vector<int> t, x, y;
  cin >> n;
  t.push_back(0);
  x.push_back(0);
  y.push_back(0);
  for (int i = 0; i < n; i++) {
    int tmpt, tmpx, tmpy;
    cin >> tmpt >> tmpx >> tmpy;
    t.push_back(tmpt);
    x.push_back(tmpx);
    y.push_back(tmpy);
  }

  int flag = 1;
  for (int i = 0; i < n; i++) {
    int dt = t[i + 1] - t[i];
    int dist = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
    if (dt < dist) {
      flag = 0;
    }
    if (dist % 2 != dt % 2) {
      flag = 0;
    }
  }

  if (flag == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}