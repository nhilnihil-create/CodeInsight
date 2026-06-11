#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

const ll INF = 1e9;
const long long INFL = 1LL<<60;


int main() {
  string s;
  cin >> s;

  if (s[0] != 'A') {
    puts("WA");
    return 0;
  }

  int st = 2;
  int ed = s.size() - 2;

  int idx = -1;

  for (int i = st; i <= ed; i++) {
    if (s[i] == 'C') {
      if (idx == -1) idx = i;
      else {
        puts("WA");
        return 0;
      }
    }
  }

  if (idx == -1) {
    puts("WA");
    return 0;
  }

  for (int i = 1; i < s.size(); i++) {
    if (i == idx) continue;
    if (s[i] < 'a' || 'z' < s[i]) {
      puts("WA");
      return 0;
    }
  }

  puts("AC");

  return 0;
}
