#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;

  int acnt = 0;
  int bcnt = 0;
  int abcnt = 0;
  int ans = 0;
  rep(i, n) {
    string s; cin >> s;
    int sn = s.size();

    bool sufa = s[sn - 1] == 'A';
    bool preb = s[0] == 'B';

    if(sufa && preb) {
      ++abcnt;
    } else {
      acnt += sufa;
      bcnt += preb;
    }

    rep1(i, sn - 1) {
      if(s[i] == 'B' && s[i - 1] == 'A') {
        ++ans;
      }
    }
  }

  ans += min(acnt, bcnt);
  if(abcnt) {
    ans += abcnt;
    if(acnt + bcnt == 0) {
      --ans;
    }
  }

  cout << ans << endl;
}
