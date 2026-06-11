#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, i, minm = INT_MAX, cnt = 0;
  cin >> n >> x;
  vector<int> m(n, 0);
  for (i = 0; i < n; ++i) {
    cin >> m[i];
    x -= m[i];
    minm = min(minm, m[i]);
  }
  while (x >= minm) {
    cnt++;
    x -= minm;
  }
  cout << n + cnt << endl;
}