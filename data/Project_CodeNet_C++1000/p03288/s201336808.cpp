#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int r;
  cin >> r;

  string result;
  if (r < 1200) {
    result = "ABC";
  } else if (r < 2800) {
    result = "ARC";
  } else {
    result = "AGC";
  }
  cout << result << endl;

  return 0;
}
