#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b;
  cin >> a >> b;

  int t2 = 1, t1 = 0;
  for (int i = 2; i < 1000; ++i) {
    t2 = t2 + i;
    t1 = t1 + i-1;
    if (t2 - b == t1 - a) {
      cout << (t2 - b) << endl;
      break;
    }
  }

  return 0;
}

