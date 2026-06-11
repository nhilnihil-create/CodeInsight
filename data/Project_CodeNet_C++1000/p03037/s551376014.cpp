#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ls(m), rs(m);
  rep(i, m) cin >> ls[i] >> rs[i];
  int l = *max_element(ls.begin(), ls.end());
  int r = *min_element(rs.begin(), rs.end());
  if (r < l) {
    cout << 0 << endl;
  } else {
    cout << r - l + 1 << endl;
  }
}
