#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, k;
  cin >> n >> k;
  vector<int64_t> a(n), dp_under(41, -1e18), dp_exact(41);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  for (int i = 39; i >= 0; i--) {
    int64_t s[2] = {0, 0};
    for (int j = 0; j < n; j++) {
      s[(a.at(j) >> i) & 1]++;
    }
    swap(s[0], s[1]);
    s[0] <<= i;
    s[1] <<= i;
    dp_under.at(i) = dp_under.at(i + 1) + max(s[0], s[1]);
    dp_exact.at(i) = dp_exact.at(i + 1) + s[(k >> i) & 1];
    if (((k >> i) & 1) == 1) {
      dp_under.at(i) = max(dp_under.at(i), dp_exact.at(i + 1) + s[0]);
    }
  }
  cout << max(dp_under.at(0), dp_exact.at(0)) << endl;
}
