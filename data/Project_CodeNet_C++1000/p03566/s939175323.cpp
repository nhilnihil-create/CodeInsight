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

int N;
int t[200], v[200];
double s[60000];
int tsum[200];
vector<double> vec;

double maxs(int tick) {
  double res = 0.5 * tick;
  // chmin(res, 0.5 * (tsum[N + 1] - tick));
  repe(i, 1, N + 1) {
    int s = tsum[i];
    int e = tsum[i + 1];
    double cv = v[i];
    if (e <= tick) {
      chmin(res, cv + 0.5 * (tick - e));
    } else if (s <= tick && tick <= e) {
      chmin(res, cv);
    } else {
      chmin(res, cv + 0.5 * (s - tick));
    }
  }
  return res;
}

int main() {
  cin >> N;
  repe(i, 1, N) {
    cin >> t[i];
    tsum[i + 1] = tsum[i] + 2 * t[i];
    tsum[i + 2] = tsum[i + 1];
  }
  repe(i, 1, N) { cin >> v[i]; }

  int tick = 0;
  repe(i, 1, N) {
    int ct = t[i];
    int cv = v[i];
    int nv = v[i + 1];
    for (int j = 1; j <= 2 * ct; ++j) {
      ++tick;
      s[tick] = min(s[tick - 1] + 0.5, maxs(tick));
    }
  }

  double ans = 0;
  rep(i, 0, tick) { vec.push_back(double(s[i] + s[i + 1]) / 4.0); }
  sort(vec.begin(), vec.end());
  for (auto e : vec) {
    ans += e;
  }
  cout << fixed << setprecision(20) << ans << endl;
}
