#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans{};
  for (int i{1}; i <= N; ++i) {
    if (i % 2 == 0) continue;
    int count{};
    for (int j{1}; j <= i; ++j) {
      if (i % j == 0) ++count;
    }
    if (count == 8)
      ++ans;
  }
  cout << ans << endl;
  return 0;
}
