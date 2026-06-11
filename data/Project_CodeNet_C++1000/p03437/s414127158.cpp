#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int gcd(int p, int q) {
  if (p % q == 0) return q;
  return gcd(q, p % q);
}

int main() {
  int x, y;
  cin >> x >> y;
  if(x >= y && gcd(x, y) == y) cout << -1 << endl;
  else cout << x << endl;
}