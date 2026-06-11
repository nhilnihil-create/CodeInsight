#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v.at(i);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int j = v.at(0)+1, ans = 0;
  rep(i, n) {
    // cout << ans << " " << j << " " << v.at(i) << endl;
    if (j > v.at(i)) {
      ans++;
      j = v.at(i);
    }
  }
  cout << ans << endl;
}
