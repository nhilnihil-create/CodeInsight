#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef int64_t ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  if (s == "zyxwvutsrqponmlkjihgfedcba") {
    puts("-1");
    return 0;
  }

  // |s| < 26 の場合，sに含まれない最小の文字を最後に付ける
  if (s.size() < 26) {
    for (int i = 0; i <= s.size(); i++) {
      if (s.find('a' + i) == string::npos) {
        s.append(1, 'a' + i);
        break;
      }
    }
    cout << s << endl;
    return 0;
  }


  // |s| == 26 の場合
  vector<char> r;
  r.push_back(s.back());
  for (int i = s.size() - 2; i >= 0; i--) {
    if (s[i] < r.back()) {
      s[i] = *lower_bound(ALL(r), s[i]);
      s.resize(i+1);
      break;
    } else {
      r.push_back(s[i]);
      sort(ALL(r));
    }
  }

  cout << s << endl;  

  return 0;
}
