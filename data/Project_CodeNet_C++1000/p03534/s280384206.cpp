#include <bits/stdc++.h>
typedef long long int ll;
#define FOR(i, a, b) for (ll i = (signed)(a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define EREP(i, n) for (int i = (n)-1; i >= 0; --i)
#define MOD 1000000007
#define pb(a) push_back((a))
#define INF 93193111451418101
#define MIN -93193111451418101
#define EPS 1e-11
#define tp(a, b, c) make_tuple(a, b, c)
using namespace std;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
template <typename T> void fill_all(T &arr, const T &v) { arr = v; }
template <typename T, typename ARR> void fill_all(ARR &arr, const T &v) {
  for (auto &i : arr) {
    fill_all(i, v);
  }
}
//------------------変数-----------------------//
//-------------------関数----------------------//

ll ch[114514], shurui = 0;
string str;
//-------------------??¢??°----------------------//

int main() {
  cin >> str;
  if (str.size() == 1) {
    cout << "YES" << endl;
    return 0;
  }
  REP(i, str.size()) {
    if (ch[str[i] - 'a'] == 0) {
      shurui++;
    }
    ch[str[i] - 'a']++;
  }
  if (shurui == 1) {
    cout << "NO" << endl;
    return 0;
  }
  sort(ch, ch + shurui);
  if (shurui == 2) {
    if (str.size() == 2) {
      cout << "YES" << endl;
      return 0;
    }
    cout << "NO" << endl;
    return 0;
  }
  if (ch[2] - ch[0] <= 1) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}
