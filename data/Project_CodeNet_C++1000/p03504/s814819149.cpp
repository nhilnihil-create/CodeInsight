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
  int n, c;
  cin >> n >> c;
  vector<vector<pair<int, int>>> pavec1(c);
  REP(i,n){
    int a, b, chan;
    cin >> a >> b >> chan;
    --chan;
    pavec1[chan].push_back(make_pair(a, b));
  }

  vector<pair<int, int>> pavec;
  REP(i,c){
    if (pavec1[i].size() == 0) continue;
    sort(pavec1[i].begin(), pavec1[i].end());
    pair<int,int> prev = pavec1[i][0];
    FOR(j, 1, pavec1[i].size()){
      if (pavec1[i][j].first == prev.second){
        prev.second = pavec1[i][j].second;
      }else{
        pavec.push_back(make_pair(prev.first, 0));
        pavec.push_back(make_pair(prev.second, 1));
        prev = pavec1[i][j];
      }
    }
    pavec.push_back(make_pair(prev.first, 0));
    pavec.push_back(make_pair(prev.second, 1));
  }

  sort(pavec.begin(), pavec.end());
  int ans = 0, tmp = 0;
  REP(i,pavec.size()){
    pint now = pavec[i];
    if (now.second == 0){
      ++tmp;
      ans = max(ans, tmp);
    } else {
      --tmp;
    }
  }
  cout << ans << endl;
}