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

  long N, M;
  cin >> N >> M;
  vector<vector<long>> A(N, vector<long>(2));
  rep(i, 0, N) {
    cin >> A[i][0] >> A[i][1];
  }
  sort_(A);
  long n;
  ll ans = 0;
  int i = 0;
  while (M > 0) {
    n = min(M, A[i][1]);
    ans += n * A[i][0];
    M -= n;
    ++i;
  }
  cout << ans << endl;
  return 0;
}
