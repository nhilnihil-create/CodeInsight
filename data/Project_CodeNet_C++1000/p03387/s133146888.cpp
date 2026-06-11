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

  array<int, 3> A;
  cin >> A[0] >> A[1] >> A[2];
  sort_(A);
  int n = A[2] - A[1];
  int ans = n;
  A[0] += n;
  A[1] += n;
  ans += ((A[2] - A[0]) + 1) / 2;
  if ((A[2] - A[0]) % 2) ++ans;
  cout << ans << endl;
  return 0;
}
