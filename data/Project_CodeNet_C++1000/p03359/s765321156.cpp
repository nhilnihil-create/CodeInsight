#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  struct tm t = {};
  t.tm_year = 2018 - 1900;
  t.tm_mon = 0;
  t.tm_mday = 0;
  int ans = 0;
  while (++t.tm_mday) {
    mktime(&t);
    if (t.tm_mon + 1 == t.tm_mday) ans++;
    if (t.tm_mon + 1 == a && t.tm_mday == b) break;
  }
  cout << ans << "\n";
}