#include <bits/stdc++.h>
using namespace std;

int n, h, w;

int main() {
  cin >> n >> h >> w;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (h <= a && w <= b) ++res;
  }
  cout << res << endl;
  return 0;
}
