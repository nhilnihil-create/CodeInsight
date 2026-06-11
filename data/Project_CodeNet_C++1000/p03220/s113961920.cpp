#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t, a;
  cin >> n >> t >> a;

  // vector<int> h(n);
  // for (int i = 0; i < n; ++i) {
  //   cin >> h.at(i);
  //   h.at(i) = abs(t * 1000 - h.at(i) * 6 - a * 1000);
  // }

  // int minnum = h.at(0);
  // for (int i = 0; i < n; ++i) {
  //   minnum = min(minnum, h.at(i));
  // }
  // for (int i = 0; i < n; ++i) {
  //   if (minnum == h.at(i)) {
  //     cout << i + 1 << endl;
  //     break;
  //   }
  // }

  int iter = 0;
  int cc = 1 << 30;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    int c = t * 1000 - h * 6 - a * 1000;
    if (c < 0) c = -c;
    if (cc > c) cc = c, iter = i;
  }
  cout << iter + 1 << endl;
}