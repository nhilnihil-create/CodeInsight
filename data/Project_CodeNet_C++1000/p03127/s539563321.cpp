#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, g;
  cin >> n >> g;
  while (--n) {
    int a;
    cin >> a;
    g = gcd(g, a);
  }
  cout << g << '\n';
  return 0;
}
