#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int x_cnt = 0;
  for (auto c : s) {
    if (c == 'x')
      ++x_cnt;
  }

  if (15 - x_cnt >= 8)
    puts("YES");
  else
    puts("NO");
}