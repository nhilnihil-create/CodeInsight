#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  vector<int> num(3);
  rep(i, num.size()) {
    cin >> num[i];
  }

  sort(num.rbegin(), num.rend());

  int ans = num[0] * 10 + num[1] + num[2];

  cout << ans << endl;
 
  return 0;
}