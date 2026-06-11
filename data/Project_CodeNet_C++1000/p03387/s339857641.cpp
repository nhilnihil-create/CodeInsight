#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  vector<int> v(3);
  rep(i, 3) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int ans = 0;

  while (!(v[0] == v[1] && v[0] == v[2])) {
    if (v[1] == v[2]) {
      int dist = v[1] - v[0];
      if (dist % 2 != 0) dist++;
      v[0] += dist;
      ans += dist / 2;
      sort(v.begin(), v.end());
    } else if (v[0] != v[1] && v[1] != v[2]) {
      int dist = v[2] - v[1];
      v[1] += dist;
      v[0] += dist;
      ans += dist;
    } else if (v[0] == v[1]) {
      int dist = v[2] - v[1];
      v[0] += dist;
      v[1] += dist;
      ans += dist;
    }
  }

  cout << ans << endl;
  
  return 0;
}