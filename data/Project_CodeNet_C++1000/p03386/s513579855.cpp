#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  for (int x = a; x <= b; x++) {
    if (x < a + k || b - k < x) {
      cout << x << endl;
    }
  }
  return 0;
}
