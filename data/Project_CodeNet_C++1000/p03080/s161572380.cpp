#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int cnt = 0;
  for (auto c : s) {
    if (c == 'R')
      ++cnt;
  }

  if (cnt > n / 2)
    puts("Yes");
  else
    puts("No");
}