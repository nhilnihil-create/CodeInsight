#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int a, b, c, m = 0;
  cin >> a >> b >> c;
  if(a + b < c - 1) cout << 2 * b + a + 1 << endl;
  else cout << b + c << endl;
  return 0;
}
