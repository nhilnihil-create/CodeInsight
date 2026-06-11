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
ll N, K;
int x[100], y[100];

bool check(int top, int bottom, int right, int left) {
  int cnt = 0;
  rep(k, 0, N) {
    int cx = x[k];
    int cy = y[k];
    if (left <= cx && cx <= right && bottom <= cy && cy <= top) {
      ++cnt;
    }
  }

  return cnt >= K;
}

int dummy[1000000];

int main() {
  cin >> N >> K;
  rep(i, 0, N) { cin >> x[i] >> y[i]; }

  for (ll i = 0; i <= 2000000000; ++i) {
    dummy[i % 1000000] = i;
  }

  ll ans = numeric_limits<ll>::max();
  rep(i, 0, N) {
    rep(j, i, N) {
      rep(k, j, N) {
        rep(l, k, N) {
          ll top = max(y[i], max(y[j], max(y[k], y[l])));
          ll bottom = min(y[i], min(y[j], min(y[k], y[l])));
          ll left = min(x[i], min(x[j], min(x[k], x[l])));
          ll right = max(x[i], max(x[j], max(x[k], x[l])));

          if (check(top, bottom, right, left)) {
            chmin(ans, (top - bottom) * (right - left));
          }
        }
      }
    }
  }

  cout << ans << endl;
}
