#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) {
    cin >> h[i];
  }

  int ans = 0;
  while (true) {
    if (*max_element(h.begin(), h.end()) == 0) break;

    int i = 0;
    while (i < n) {
      if (h[i] == 0) ++i;
      else {
        ++ans;
        while (i < n && h[i] > 0) {
          --h[i];
          ++i;
        }
      }
    }
  }

  cout << ans << endl;  
  return 0;
}