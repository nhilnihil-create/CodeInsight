#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
const double PI = 3.14159265358979323846;
template <class T, class U>
void chmin(T& t, const U& u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
  if (t < u) t = u;
}

int main(void) {
  string s;
  cin >> s;
  int res = 0;
  rep(i, s.size()) {
    int cnt = 0;
    for (int j = i; j < s.size(); j++) {
      if (s[j] != 'A' && s[j] != 'C' && s[j] != 'G' && s[j] != 'T') break;
      ++cnt;
    }
    chmax(res, cnt);
  }
  cout << res << endl;
  return 0;
}