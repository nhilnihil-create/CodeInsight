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
  int k = f(0);
  int lo = 0, hi = N - 1;
  while (lo <= hi) {
    int mi = (lo + hi) / 2;
    int t = f(mi);
    if ((k == t && mi % 2 == 0) || (k != t && mi % 2 == 1)) {
      lo = mi + 1;
    } else {
      hi = mi - 1;
    }
  }
  return 0;
}
