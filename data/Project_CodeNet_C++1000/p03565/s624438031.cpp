#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
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

string Sd, T;

int main() {
  cin >> Sd >> T;

  if (T.size() > Sd.size()) {
    cout << "UNRESTORABLE";
    return 0;
  }

  int tstart;
  for (int i = Sd.size() - T.size(); i >= 0; --i) {
    bool can = true;
    for (int j = 0; j < T.size(); ++j) {
      if (Sd[i + j] != T[j] && Sd[i + j] != '?') {
        can = false;
        break;
      }
    }
    if (can) {
      tstart = i;
      break;
    }

    if (i == 0) {
      cout << "UNRESTORABLE";
      return 0;
    }
  }

  for (int i = 0; i < Sd.size(); ++i) {
    if (tstart <= i && i < tstart + T.size()) {
      cout << T[i - tstart];
      continue;
    }

    if (Sd[i] == '?') {
      cout << "a";
    } else {
      cout << Sd[i];
    }
  }
}
