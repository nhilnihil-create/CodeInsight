#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> cnt(4);
  for (int i = 0; i < 6; ++i) {
    int n;
    cin >> n;
    cnt[--n]++;
  }

  int m = 0;
  for (auto c : cnt)
    m = max(m, c);

  if (m < 3)
    puts("YES");
  else
    puts("NO");
}