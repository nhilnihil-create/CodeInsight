#include <bits/stdc++.h>

//#include <atcoder/all>

using namespace std;
// using namespace atcoder;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> wsum(n + 1, 0), bsum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '.') {
      wsum[i] = wsum[i - 1] + 1;
      bsum[i] = bsum[i - 1];
    } else {
      wsum[i] = wsum[i - 1];
      bsum[i] = bsum[i - 1] + 1;
    }
    //  cout << wsum[i] << ' ' << bsum[i] << endl;
  }

  int ans = (1U << 31) - 1;
  for (int i = 0; i <= n; i++) {
    int change = 0;
    // 0~i番目を白にする。(0番目は無し)
    change += bsum[i] - bsum[0];
    // i+1~n 番目を黒にする。
    change += wsum[n] - wsum[i];
    ans = min(ans, change);
  }

  cout << ans << endl;
}