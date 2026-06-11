#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) \
  for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) \
  for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define VREP(s, ite) for (auto ite = s.begin(); ite != s.end(); ++ite)
#define FI first
#define SE second
#define ALL(v) v.begin(), v.end()
//#define endl "\n"
#define ciosup \
  cin.tie(0);  \
  ios::sync_with_stdio(false);
#define eb emplace_back
#define vint vector<int>
constexpr ll INF = 1e15 + 7LL;
constexpr ll MOD = 998244353;

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (int i = 0; i < v.size(); ++i) {
    is >> v[i];
  }
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size() - 1; ++i) {
    os << v[i] << " ";
  }
  if (v.size() > 0) {
    os << v[v.size() - 1] << endl;
  }
  return os;
}

int main() {
  int d,g;
  cin >> d >> g;
  vint p(d), c(d);
  REP(i, d) { cin >> p[i] >> c[i]; }
  int ans = INT_MAX;
  REP(i, (1 << d)) {
    ll sum = 0;
    int cnt = 0;
    vector<bool> full(d, false);
    REP(j,d){
      if (i & (1 << j)){
        full[j] = true;
        sum += c[j];
        sum += p[j] * (100 * (j + 1));
        cnt += p[j];
      }
    }
    if (sum >= g) {
      ans = min(ans,cnt);
      continue;
    }
    IREP(j, d){
      if (full[j]){
        continue;
      }
      int total_pos = (100 * (j + 1)) * (p[j] - 1);
      if (g - sum <= total_pos){
        int rem = g - sum;
        if (rem % (100 * (j + 1)) == 0) {
          cnt += rem / (100 * (j + 1));
        } else {
          cnt += 1 + rem / (100 * (j + 1));
        }
        ans = min(ans, cnt);
      }
      break;
    }
  }
  cout << ans << endl;
}