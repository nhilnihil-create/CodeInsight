#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

const double pi = 3.141592653589793;
// -------------------------------------------------------
int N;
map<char, ll> mp;

int main() {
  cin >> N;
  rep(i, 0, N) {
    string s;
    cin >> s;
    mp[s[0]]++;
  }

  char cs[] = {'M', 'A', 'R', 'C', 'H'};
  ll ans = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      for (int k = j + 1; k < 5; ++k) {
        ans += mp[cs[i]] * mp[cs[j]] * mp[cs[k]];
      }
    }
  }
  cout << ans << endl;
}