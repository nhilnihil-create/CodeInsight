#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> cnt(4, 0);
  for (int i = 0; i < 3; ++i) {
    int v, u;
    cin >> v >> u;
    v--; u--;
    cnt[v]++; cnt[u]++;
  }

  bool is_valid = true;
  for (int i = 0; i < 4; ++i) {
    if (cnt[i] > 2) is_valid = false;
  }

  if (is_valid) puts("YES");
  else puts("NO");
  return 0;
}
