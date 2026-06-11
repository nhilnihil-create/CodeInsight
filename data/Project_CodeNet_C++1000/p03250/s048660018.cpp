#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (max(a, max(b, c)) == a) cout << 10 * a + b + c << endl;
  else if (max(a, max(b, c)) == b) cout << 10 * b + a + c << endl;
  else cout << 10 * c + a + b << endl;
}