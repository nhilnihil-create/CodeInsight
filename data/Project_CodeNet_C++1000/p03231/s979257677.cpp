#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  bool can = true;
  long long L = 1LL * n / __gcd(n, m) * m;
  long long np = L / n, mp = L / m;
  for (int i = 0; i < n; i++) {
    if (np * i % mp == 0) {
      can &= s[i] == t[np * i / mp];
    }
  }
  cout << (can ? L : -1) << '\n';
  return 0;
}
