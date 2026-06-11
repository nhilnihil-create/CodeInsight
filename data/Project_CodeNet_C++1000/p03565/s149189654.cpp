#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define inf 10e17
#define rep(i, n) for(long long i=0; i<n; i++)
#define repr(i, n, m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template<class T>
inline void chmax(T &ans, T t) { if (t > ans) ans = t; }

template<class T>
inline void chmin(T &ans, T t) { if (t < ans) ans = t; }

int main() {
  string s, t;
  cin >> s >> t;

  auto lens = s.size();
  auto lent = t.size();

  if (lent > lens) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  string ans = "";
  for (int i = 0; i <= lens - lent; ++i) {
    string tmp = s;
    // ? だったらなんでもおｋ
    bool flag = true;
    for (int j = 0; j < lent; ++j) {
      auto idx = j + i;
      if (s[idx] != '?' && s[idx] != t[j]) {
        flag = false;
        break;
      } else {
        tmp[idx] = t[j];
      }
    }

    for (auto &it : tmp) {
      if (it == '?') it = 'a';
    }

    if (flag) {
      if (ans.empty()) ans = tmp;
      else chmin(ans, tmp);
    }
  }

  if (ans.empty()) {
    cout << "UNRESTORABLE" << endl;
  } else {
    cout << ans << endl;
  }
}
