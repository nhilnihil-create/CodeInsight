#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) stable_sort(a.begin(), a.end())
#define rsort(a) stable_sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define join(a, d) accumulate(a.begin() + 1, a.end(), a[0], [](string s, string t) { return s + d + t; })
#define all(a) a.begin(), a.end()
#define degrees(a) a * 180.0 / M_PI;
#define radians(a) (a * M_PI) / 180.0;
// #define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int N;
  cin >> N;
  vector<int> D(N, 0);
  rep(i, 0, N) cin >> D[i];
  rsort(D);

  int prev = 0;
  int ans = 1;
  for (auto d : D) {
    if (d < prev) {
      ++ans;
    }
    prev = d;
  }
  cout << ans << endl;
  return 0;
}
