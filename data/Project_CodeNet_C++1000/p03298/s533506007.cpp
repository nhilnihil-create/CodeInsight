#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template <class S, class T>
ostream& operator<<(ostream& out, const pair<S, T>& o) {
  out << "(" << o.first << "," << o.second << ")";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& V) {
  for (int i = 0; i < V.size(); i++) {
    out << V[i];
    if (i != V.size() - 1) out << " ";
  }
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<vector<T> >& Mat) {
  for (int i = 0; i < Mat.size(); i++) {
    if (i != 0) out << endl;
    out << Mat[i];
  }
  return out;
}
template <class S, class T>
ostream& operator<<(ostream& out, const map<S, T>& mp) {
  out << "{ ";
  for (auto it = mp.begin(); it != mp.end(); it++) {
    out << it->first << ":" << it->second;
    if (mp.size() - 1 != distance(mp.begin(), it)) out << ", ";
  }
  out << " }";
  return out;
}
template <typename T>
vector<T> make_v(size_t a) {
  return vector<T>(a);
}
template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T& t, const V& v) {
  t = v;
}
template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T& t, const V& v) {
  for (auto& e : t) fill_v(e, v);
}
/*
 <url:https://atcoder.jp/contests/agc026/tasks/agc026_c>
 問題文============================================================
 C - String Coloring
 =================================================================
 解説=============================================================
 ================================================================
 */

template <class Type>
Type solve(Type res = Type()) {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string lS = S.substr(0, N);

  string rS = S.substr(N, 2 * N);
  reverse(rS.begin(), rS.end());

  using pss = pair<string, string>;
  map<pss, ll> mp;
  {  // lSから赤・青の組み合わせを列挙
    for (int i = 0; i < (1 << N); i++) {
      string r, b;
      for (int j = 0; j < N; j++) {
        if ((i >> j) & 1) {
          r += lS[j];
        } else {
          b += lS[j];
        }
      }
      reverse(b.begin(), b.end());
      mp[make_pair(r, b)]++;
    }
  }
  {  // rSから赤・青の組み合わせを列挙　⇒　lSでのmapを用いて計算
    for (int i = 0; i < (1 << N); i++) {
      string r, b;
      for (int j = 0; j < N; j++) {
        if ((i >> j) & 1) {
          b += rS[j];
        } else {
          r += rS[j];
        }
      }
      reverse(b.begin(), b.end());
      res += mp[make_pair(r,b)];
    }
  }
  // cout << mp << endl;
  return res;
}
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // solve<ll>(0);
  cout << fixed << setprecision(12) << solve<ll>() << endl;
  return 0;
}