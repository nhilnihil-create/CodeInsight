#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  ll k;
  cin >> s >> k;

  for (int i = 0; i < min((ll)s.size(), k); i++) {
    int n = s[i] - '0';
    if (n > 1) {
      printf("%d\n", n);
      return 0;
    }
  }
  puts("1");

  return 0;
}
