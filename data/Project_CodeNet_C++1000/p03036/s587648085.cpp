#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int r, D, x;
  cin >> r >> D >> x;
  vector<int> ans(11);
  ans[0] = x;
  rep(i, 10) {
    ans[i+1] = r * ans[i] - D;
  }
  rep(i, 10) {
    cout << ans[i+1] << endl;
  }
}