#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;

const int TR = 200002;
int sm[TR], tt[TR];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, TC; cin >> N >> TC;
  int S[N], T[N], C[N];
  rep(i, N) {
    cin >> S[i] >> T[i] >> C[i];
  }

  rep1(c, TC) {
    rep(i, TR) tt[i] = 0;
    rep(i, N) {
      if(C[i] == c) {
        tt[S[i] * 2 - 1]++;
        tt[T[i] * 2]--;
      }
    }
    rep1(i, TR-1) {
      tt[i] += tt[i - 1];
    }
    rep(i, TR) {
      if(tt[i] > 0) sm[i]++;
    }
  }

  int ans = 0;
  rep(i, TR) {
    ans = max(ans, sm[i]);
  }
  cout << ans << endl;
}
