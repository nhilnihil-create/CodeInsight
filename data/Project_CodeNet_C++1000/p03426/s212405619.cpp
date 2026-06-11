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
ll H, W, D;
ll A[400][400];
ll Q;
ll L[101010];
ll R[101010];

using Pii = pair<int, int>;
map<int, Pii> mp;

ll sum[201010];

int main() {
  cin >> H >> W >> D;
  repe(i, 1, H) {
    repe(j, 1, W) {
      cin >> A[i][j];
      mp[A[i][j]] = make_pair(i, j);
    }
  }
  cin >> Q;
  rep(i, 0, Q) { cin >> L[i] >> R[i]; }

  for (int i = 1; i <= D; ++i) {
    ll cur_num = i;
    while (cur_num <= H * W) {
      auto cur = mp[cur_num];
      cur_num += D;
      auto next = mp[cur_num];
      sum[cur_num] = sum[cur_num - D] + abs(cur.first - next.first) +
                     abs(cur.second - next.second);
    }
  }

  rep(i, 0, Q) {
    ll l = L[i];
    ll r = R[i];

    ll cur_num = l;
    ll ans = sum[r] - sum[l];

    cout << ans << "\n";
  }
}
