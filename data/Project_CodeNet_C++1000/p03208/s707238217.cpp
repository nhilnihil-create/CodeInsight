#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, k;
  cin >> n >> k;
  
  vector<int64_t> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h.at(i);
  }
  
  sort(h.begin(), h.end());
  
  int64_t ans;
  for (int i = 0; i <= n - k; i++) {
    if (i == 0) {
      ans = h.at(k + i - 1) - h.at(i);
    }
    else {
      ans = min(ans, h.at(k + i - 1) - h.at(i));
    }
  }
  cout << ans << endl;
}
