#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> a(4);
  rep(i, a.size()) cin >> a[i];
  sort(a.begin(), a.end());
  bool flag = false;
  if(a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9) flag = true;

  cout << (flag ? "YES" : "NO") << '\n';
  return 0;
}
