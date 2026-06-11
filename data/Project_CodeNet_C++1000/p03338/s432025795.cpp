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

// -------------------------------------------------------
int N;
string S;

int main() {
  cin >> N >> S;
  int ans = 0;
  rep(i, 1, N) {
    set<char> chars1;
    set<char> chars2;
    int cnt = 0;
    rep(j, 0, i) { chars1.insert(S[j]); }
    rep(j, i, N) { chars2.insert(S[j]); }
    for (char c = 'a'; c <= 'z'; ++c) {
      if (chars1.count(c) == 1 && chars2.count(c) == 1) {
        ++cnt;
      }
    }
    chmax(ans, cnt);
  }
  cout << ans << endl;
}
