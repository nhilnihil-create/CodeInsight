#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s; cin >> s;
  int ss = s.size();

  ll ans = 0;
  int a = 0;

  rep(i, ss) {
    if(s[i] == 'A') ++a;
    else if(s[i] == 'B') {
      if(i + 1 < ss && s[i + 1] == 'C') {
        ans += a;
        ++i;
      } else {
        a = 0;
      }
    } else {
      a = 0;
    }
  }

  cout << ans << endl;
}
