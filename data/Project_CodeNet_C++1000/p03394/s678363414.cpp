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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n;
  cin >> n;
  vll ans;

  if (n == 3) {
    ans.push_back(2);
    ans.push_back(5);
    ans.push_back(63);
  } else if (n == 4) {
    ans.push_back(2);
    ans.push_back(5);
    ans.push_back(20);
    ans.push_back(63);
  } else {
    ll v = 0;
    while (n >= 8) {
      ans.push_back(v + 2);
      ans.push_back(v + 3);
      ans.push_back(v + 4);
      ans.push_back(v + 6);
      ans.push_back(v + 8);
      ans.push_back(v + 9);
      ans.push_back(v + 10);
      ans.push_back(v + 12);
      v += 12;
      n -= 8;
    }

    switch (n) {
    case 1:
      ans.push_back(v + 12);
      break;
    case 2:
      ans.push_back(v + 6);
      ans.push_back(v + 12);
      break;
    case 3:
      ans.push_back(v + 3);
      ans.push_back(v + 9);
      ans.push_back(v + 12);
      break;
    case 4:
      ans.push_back(v + 2);
      ans.push_back(v + 4);
      ans.push_back(v + 6);
      ans.push_back(v + 12);
      break;

    case 5:
      ans.push_back(v + 2);
      ans.push_back(v + 4);
      ans.push_back(v + 6);
      ans.push_back(v + 3);
      ans.push_back(v + 9);
      break;

    case 6:
      ans.push_back(v + 2);
      ans.push_back(v + 4);
      ans.push_back(v + 6);
      ans.push_back(v + 3);
      ans.push_back(v + 9);
      ans.push_back(v + 12);
      break;

    case 7:
      ans.push_back(v + 2);
      ans.push_back(v + 3);
      ans.push_back(v + 4);
      ans.push_back(v + 6);
      ans.push_back(v + 8);
      ans.push_back(v + 9);
      ans.push_back(v + 10);
      break;

    default:
      break;
    }
  }

  for (auto it : ans) {
    cout << it << " ";
  }
  cout << endl;

  return 0;
}
