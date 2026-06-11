#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) stable_sort(a.begin(), a.end())
#define rsort(a) stable_sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define join(a, d) accumulate(a.begin() + 1, a.end(), a[0], [](string s, string t) {return s + d + t;})
#define all(a) a.begin(), a.end()
// #define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> H(N);
  rep(i, 0, N) {
    cin >> H[i];
  }
  int ans = 0;
  bool flag = false;
  while (sum(H)) {
    rep(i, 0, N) {
      if (H[i]) {
        --H[i];
        flag = true;
      } else {
        if (flag) ++ans;
        flag = false;
      }
    }
    if (flag) ++ans;
    flag = false;
  }
  cout << ans << endl;
  return 0;
}
