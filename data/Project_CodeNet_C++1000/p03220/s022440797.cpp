#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t, a;
  cin >> n >> t >> a;

  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h.at(i);
    h.at(i) = abs(t * 1000 - h.at(i) * 6 - a * 1000);
  }

  int minnum = h.at(0);
  for (int i = 0; i < n; ++i) {
    minnum = min(minnum, h.at(i));
  }
  for (int i = 0; i < n; ++i) {
    if (minnum == h.at(i)) {
      cout << i + 1 << endl;
      break;
    }
  }
}