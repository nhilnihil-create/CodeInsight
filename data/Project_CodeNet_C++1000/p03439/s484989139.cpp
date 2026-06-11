#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  auto f = [](int x) {
    cout << x << '\n';
    cout << flush;
    string s;
    cin >> s;
    if (s == "Vacant") {
      exit(0);
    } else if (s == "Male") {
      return 0;
    } else {
      return 1;
    }
  };
  int lo = 0, hi = N - 1, k = f(0);
  while (lo <= hi) {
    int mi = (lo + hi) / 2, r = f(mi) ^ (mi & 1);
    if (k == r) {
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  return 0;
}
