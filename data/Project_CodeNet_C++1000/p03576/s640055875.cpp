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
Pll p[100];

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
  rep(i, 0, N) {
    cin >> x[i] >> y[i];
    p[i] = Pll(x[i], y[i]);
  }

  sort(p, p + N);

  ll ans = numeric_limits<ll>::max();
  rep(i, 0, N) {
    rep(j, 0, N) {
      ll top = p[i].second;
      ll bottom = p[j].second;
      if (bottom > top) continue;

      ll cnt = 0;
      if (bottom <= p[0].second && p[0].second <= top) {
        ++cnt;
      }

      ll r = 1;
      ll right;
      rep(l, 0, N - 1) {
        auto pl = p[l];
        ll left = pl.first;
        bool left_included = false;
        if (bottom <= pl.second && pl.second <= top) {
          left_included = true;
        }

        while (r < N && cnt < K) {
          auto pr = p[r];
          right = pr.first;
          if (bottom <= pr.second && pr.second <= top) {
            ++cnt;
          }
          ++r;
        }
        if (cnt >= K) {
          chmin(ans, (top - bottom) * (right - left));
        }
        if (left_included) {
          --cnt;
        }
      }
    }
  }

  cout << ans << endl;
}
