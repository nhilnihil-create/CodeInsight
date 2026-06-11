#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  for (int i = a; i <= b; i++) {
    if (i >= a + k && i <= b - k) {
      continue;
    }
    cout << i << endl;
  }
  return 0;
}
