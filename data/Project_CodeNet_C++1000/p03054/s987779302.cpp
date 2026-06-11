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
constexpr ll MOD = 1e9 + 7LL;

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
  int h,w,n;
  cin >> h >> w >> n;
  int sr, sc;
  cin >> sr >> sc;
  --sr;
  --sc;
  string s, t;
  cin >> s >> t;
  int tmp = sr;
  REP(i,n){
    if (s[i] == 'U') {
      tmp--;
    }
    if (tmp < 0) {
      cout << "NO" << endl;
      return 0;
    }
    if (t[i] == 'D' && tmp < h - 1){
      tmp++;
    }
  }
  tmp = sr;
  REP(i, n) {
    if (s[i] == 'D'){
      tmp++;
    }
    if (tmp > h - 1) {
      cout << "NO" << endl;
      return 0;
    }
    if (t[i] == 'U' && tmp > 0){
      tmp--;
    }
  }
  tmp = sc;
  REP(i, n) {
    if (s[i] == 'L'){
      tmp--;
    }
    if (tmp < 0) {
      cout << "NO" << endl;
      return 0;
    }
    if (t[i] == 'R' && tmp < w - 1){
      tmp++;
    }
  }
  tmp = sc;
  REP(i, n) {
    if (s[i] == 'R'){
      tmp++;
    }
    if (tmp > w - 1) {
      cout << "NO" << endl;
      return 0;
    }
    if (t[i] == 'L' && tmp > 0){
      tmp--;
    }
  }
  cout << "YES" << endl;
}