#include <bits/stdc++.h>
using namespace std;

// boost
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using vld = vector<ld>;
using vvld = vector<vld>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
// #define mod (998244353ll)

const long long INF = 1LL << 60;

bool solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  // りんごマートはある日の朝に開店し，その時にはジュースの在庫がA本ありました。
  // すぬけ君は毎日昼にりんごマートでジュースをB本買います。
  // りんごマートでは毎日夜にジュースの在庫を確認し，
  // C本以下だった場合，次の日の朝までにD本在庫を追加します。

  // はじめから無い
  if (a < b)
    return false;

  // 充填数のほうが消費数よりも少ない
  if (b > d)
    return false;

  if (c >= b)
    return true;

  a %= b;
  ll step = gcd(b, d);

  a += ((b - a - 1) / step) * step;
  if (a > c)
    return false;

  return true;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll t;
  cin >> t;
  rep(i, t) {
    bool b = solve();
    cout << ((b) ? "Yes" : "No") << endl;
  }

  return 0;
}
