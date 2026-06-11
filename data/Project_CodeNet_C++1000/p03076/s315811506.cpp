#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  vector<int> a(5);
  for (int i = 0; i < 5; i++)
    cin >> a[i];
  int res = numeric_limits<int>::max();
  sort(begin(a), end(a));
  do {
    int cur = 0;
    for (int i = 0; i < 5; i++) {
      if (cur % 10)
        cur += 10 - cur % 10;
      cur += a[i];
    }
    res = min(res, cur);
  } while (next_permutation(begin(a), end(a))); 
  cout << res << '\n';
  return 0;
}