#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define pb push_back
#define COUT(x) cout << (x) << endl
#define COUTF(x) cout << setprecision(15) << (x) << endl
#define ENDL cout << endl
#define DF(x) x.erase(x.begin())  // 先頭文字削除
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(ALL(x))
#ifdef _DEBUG
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
#else
#define debug(x)
#endif
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr double PI = 3.141592653589793238462643383279;
ll getDigit(ll x) {
  return x == 0 ? 1 : log10(x) + 1;
}

signed main() {
  ll N;
  cin >> N;
  vector<ll> A, B, C;
  rep(j, 3) {
    rep(i, N) {
      ll t;
      cin >> t;
      if (j == 0) {
        A.pb(t);
      }
      if (j == 1) {
        B.pb(t);
      }
      if (j == 2) {
        C.pb(t);
      }
    }
  }
  SORT(A);
  SORT(B);
  SORT(C);

  ll ans = 0;
  rep(i, N) {
    ll num = B[i];
    ll indexA = lower_bound(ALL(A), num) - A.begin();
    ll indexC = upper_bound(ALL(C), num) - C.begin();
    // debug(i);
    // debug(num);
    // debug(indexA);
    // debug(indexC);
    ans += indexA * (N - indexC);
  }
  COUT(ans);

  return 0;
}