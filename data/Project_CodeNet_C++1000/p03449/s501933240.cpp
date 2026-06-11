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
  vector<int> A1(N + 1, 0);
  vector<int> A2(N + 1, 0);
  rep(i, 1, N + 1) {
    cin >> A1[i];
  }
  rep(i, 1, N + 1) {
    cin >> A2[i];
  }
  vector<int>a1(N + 1);
  vector<int>a2(N + 1);
  partial_sum(all(A1), a1.begin());
  partial_sum(all(A2), a2.begin());
  int ans = 0;
  rep(i, 1, N + 1) {
    ans = max(ans, a1[i] + a2[N] - a2[i-1]);
  }
  cout << ans << endl;
  return 0;
}
