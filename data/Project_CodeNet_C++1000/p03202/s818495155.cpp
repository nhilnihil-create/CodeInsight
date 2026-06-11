#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0, max_i = (n); i < max_i; i++)
#define REPI(i, a, b) for (int i = (a), max_i = (b); i < max_i; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define fi first
#define se second
#define int long long
using namespace std;
using ll = long long;
using II = pair<int, int>; using VII = vector<II>; using VVII = vector<VII>;
using VI = vector<int>; using VVI = vector<VI>; using VVVI = vector<VVI>;
template <class T = int> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T = int> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <class T> ostream& operator<<(ostream &s, const vector<T>& d) { int n = d.size(); REP (i, n) s << d[i] << " "; return s; }
template <class T> ostream& operator<<(ostream &s, const vector<vector<T>>& dd) { for (vector<T> d: dd) s << d << endl; return s; }
template <class T, class S> ostream& operator<<(ostream &s, const pair<T, S>& p) { s << "{" << p.first << ", " << p.second << "}"; return s; }
template <class T, class S> ostream& operator<<(ostream &s, const map<T, S> m) { for (pair<T, S> p: m) s << p << endl; return s; }
#ifdef _MY_DEBUG
  #define dump(...) cerr << "\t" << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << endl << "\t", dump_func(__VA_ARGS__);
#else
  #define dump(...)
#endif
void dump_func() { cerr << endl; }
template <class Head, class... Tail> void dump_func(Head&& h, Tail&&... t) { cerr << h << (sizeof...(Tail) == 0 ? "" : ", "), dump_func(forward<Tail>(t)...); }
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
constexpr int MOD = 1e9 + 7;

int N;
bool check(int m, VI& A) {
  if (m == 1) {
    // 狭義単調増加かどうか
    REP (i, N - 1) {
      if (A[i + 1] <= A[i]) {
        return false;
      }
    }
    return true;
  }
  map<int, int> mp;
  REP (i, N) {
    if (i == 0 || A[i] > A[i - 1]) continue;
    int k = A[i];
    mp[k]++;
    while (mp[k] >= m) {
      if (k == 1) {
        return false;
      }
      mp.erase(mp.find(k));
      k--;
      mp[k]++;
    }
    while (!mp.empty() && mp.rbegin()->fi > A[i]) {
      mp.erase(prev(mp.end()));
    }
  }
  return true;
}
signed main() {
  cin >> N;
  VI A = VI(N);
  REP (i, N) cin >> A[i];
  int l = 0, r = N;
  while (r - l > 1) {
    int m = (l + r) / 2;
    (check(m, A) ? r : l) = m;
  }
  cout << r << endl;
}
