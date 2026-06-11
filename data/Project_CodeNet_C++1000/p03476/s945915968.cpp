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
  ll Q;
  cin >> Q;

  ll N = 100009;
  ll sosu[N];
  rep(i, N) {
    sosu[i] = 1;
  }
  sosu[0] = 0;
  sosu[1] = 0;
  rep(i, N) {
    if (sosu[i] == 1) {
      rep2(j, i + 1, N) {
        if (sosu[j] == 1 && j % i == 0) {
          sosu[j] = 0;
        }
      }
    }
  }

  ll like2017[N];
  rep(i, N) {
    if (sosu[i] == 1 && sosu[(i + 1) / 2] == 1) {
      like2017[i] = 1;
    } else {
      like2017[i] = 0;
    }
    // debug(like2017[i]);
  }

  ll wa[N];
  rep(i, N) {
    if (i == 0) {
      wa[i] = 0;
      continue;
    }
    wa[i] = wa[i - 1] + +like2017[i];
    // debug(wa[i]);
  }

  rep(i, Q) {
    ll a, b;
    cin >> a >> b;
    COUT(wa[b] - wa[a - 1]);
  }

  // ll before = 0;
  // rep(i, N) {
  //   if (!f[i] && !f[(i + 1) / 2]) {
  //     wa[i] = before + 1;
  //     before = before + 1;
  //   } else {
  //     wa[i] = before;
  //   }
  // }

  // rep(i, Q) {
  //   ll a, b;
  //   cin >> a >> b;
  //   // debug(a);
  //   // debug(b);
  //   // debug(wa[a]);
  //   // debug(wa[b]);
  //   if (a == b && !f[a]) {
  //     COUT(1);
  //   } else {
  //     ll ans = wa[b] - wa[a];
  //     if (!f[a] && !f[(a + 1) / 2]) {
  //       COUT(ans + 1);
  //     } else {
  //       COUT(ans);
  //     }
  //   }
  // }

  return 0;
}