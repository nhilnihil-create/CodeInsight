#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) sort(a.begin(), a.end())
#define rsort(a) sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;
  int ans = 0;
  for (auto s : S) {
    if (s == '-')
      --ans;
    else
      ++ans;
  }
  cout << ans << endl;
  return 0;
}
