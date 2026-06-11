#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int X = max({A, B, C});
  if (X % 2 != (A + B + C) % 2) X++;
  cout << (3 * X - A - B - C) / 2 << endl;
  return 0;
}