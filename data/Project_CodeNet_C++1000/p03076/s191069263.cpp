#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  vector<int> time(5);
  rep(i,5) cin >> time[i];
  sort(time.begin(), time.end());
  int ans = 100000000;
  do {
    int res = 0;
    rep(i,4) res += ceil(time[i]/10.0) * 10;
    res += time[4];
    ans = min(ans, res);
  } while(next_permutation(time.begin(), time.end()));
  cout << ans << endl;
}