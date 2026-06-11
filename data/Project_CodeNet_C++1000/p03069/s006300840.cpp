#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0, __##i##_length = (n); i < __##i##_length; i++)
#define rep_reverse(i, n) for (ll i = (n)-1; 0 < i; i--)
#define FOR(i, from, to)                                                       \
  for (ll i = (from), __##i##_end = (to); i < __##i##_end; i++)
#define FOR_REVERSE(i, from, to)                                               \
  for (ll i = (to)-1, __##i##_end = (from); __##i##_end <= i; i--)
#define foreach(e, v) for (const auto e : (v))
#define vfree(v) std::vector<int>().swap(v)
#define DEBUG(x) cout << #x << " = " << (x) << endl

using namespace std;
typedef int64_t ll;
typedef vector<ll> llv;
typedef vector<llv> llvv;

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  llv to_dot(n + 1, 0);
  llv to_sharp(n + 1, 0);
  rep(i, n) {
    if (s[i] == '#')
      to_dot[i + 1] = to_dot[i] + 1;
    else
      to_dot[i + 1] = to_dot[i];
  }
  rep_reverse(i, n) {
    if (s[i] == '.')
      to_sharp[i - 1] = to_sharp[i] + 1;
    else
      to_sharp[i - 1] = to_sharp[i];
  }
  ll min_change = n;
  rep(i, n) min_change = min(to_dot[i] + to_sharp[i], min_change);
  cout << min_change << endl;
  return 0;
}
