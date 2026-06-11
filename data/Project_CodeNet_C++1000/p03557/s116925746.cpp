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
ll N;
vector<ll> A, B, C;

int main() {
  cin >> N;
  rep(i, 0, N) {
    ll a;
    cin >> a;
    A.push_back(a);
  }
  rep(i, 0, N) {
    ll b;
    cin >> b;
    B.push_back(b);
  }
  rep(i, 0, N) {
    ll c;
    cin >> c;
    C.push_back(c);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  ll ans = 0;
  for (auto e : B) {
    auto lb = lower_bound(A.begin(), A.end(), e);
    ll lidx = lb - A.begin();

    auto ub = upper_bound(C.begin(), C.end(), e);
    ll uidx = ub - C.begin();
    ll unum = N - uidx;

    ans += lidx * unum;
  }

  cout << ans << endl;
}
