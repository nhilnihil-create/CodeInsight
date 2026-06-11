#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100'020;
char s[N];
int n;

int main() {
  cin >> (s + 1);
  n = strlen(s + 1);
  int mn = n;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i + 1])
        mn = min(mn, max(i, n - i));
  }
  cout << mn << '\n';

  return 0;
}