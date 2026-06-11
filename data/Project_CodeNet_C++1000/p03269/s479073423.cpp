#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int L;
  cin >> L;
  int n(0), m(-3);
  stack<int> stk;
  while (L) {
    if (L & 1) {
      stk.push(n);
      m++;
    }
    L /= 2;
    n += 1;
    m += 2;
  }
  stk.pop();
  cout << n << ' ' << m << '\n';
  for (int i = 1; i <= n - 1; i++) {
    cout << i << ' '  << i + 1 << ' ' << (1 << (i - 1)) <<'\n';
    cout << i << ' '  << i + 1 << ' ' << 0 <<'\n';
  }
  int wt = (1 << (n - 1));
  while (!stk.empty()) {
    int s = stk.top() + 1;
    stk.pop();
    cout << s << ' ' << n << ' ' << wt << '\n';
    wt += (1 << (s - 1));
  }
  return 0;
}