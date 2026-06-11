#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  rep(i, n) cin >> x[i];

  auto get_times = [&](int l, int r) {
    int l_time = x[l];
    int r_time = x[r];
    if(l_time >= 0 && r_time >= 0) {
      return abs(r_time);
    }
    if(l_time < 0 && r_time < 0) {
      return abs(l_time);
    }
    if(l_time < 0 && r_time >= 0) {
      return min(abs(l_time) * 2 + abs(r_time), abs(r_time) * 2 + abs(l_time));
    }
    return -1;
  };

  int l = 0;
  int r = k - 1;

  int ans = 2147483647;
  while(r < n) {
    int t = get_times(l, r);
    ans = min(ans, t);
    l++;
    r++;
  }

  cout << ans << endl;
  return 0;
}
