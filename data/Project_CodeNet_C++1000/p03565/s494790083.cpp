#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1e9;
const long long INFLL = 1LL<<60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;
  if (s.size() < t.size()) {
    puts("UNRESTORABLE");
    return 0;
  }

  int idx = -1;
  for (int i = s.size() - t.size(); i >= 0; i--) {
    bool flag = true;
    for (int j = 0; j < t.size(); j++) {
      if (s[i+j] != t[j] && s[i+j] != '?') {
        flag = false;
        break;
      }
    }
    if (flag) chmax(idx, i);
  }

  if (idx == -1) {
    puts("UNRESTORABLE");
    return 0;
  }

  rep(i, t.size()) {
    s[idx+i] = t[i];
  }

  rep(i, s.size()) {
    if (s[i] == '?') s[i] = 'a';
  }

  cout << s << endl;

  return 0;
}
