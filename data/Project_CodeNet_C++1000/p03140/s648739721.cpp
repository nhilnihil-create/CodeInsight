#include <bits/stdc++.h>
using namespace std;

int check(char a, char b, char c) {
  if (a == b && b == c) {
    return 0;
  }

  if (a == b && b != c) {
    return 1;
  }

  if (a == c && c != b) {
    return 1;
  }

  if (b == c && c != a) {
    return 1;
  }

  if (a != b && b != c) {
    return 2;
  }

  return 0;
}

int main() {
  int n;
  string a, b, c;
  cin >> n >> a >> b >> c;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += check(a[i], b[i], c[i]);
  }

  cout << ans << endl;
  return 0;
}