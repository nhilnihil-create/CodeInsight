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
int N, K;
int x[100], y[100];
Pii p[100];
Pii praw[100];

int csum[100][100];

int cntincluded(int top, int bottom, int right, int left) {
  int topy = p[top].second;
  int bottomy = p[bottom].second;
  int rightx = p[right].first;
  int leftx = p[left].first;

  return csum[rightx][topy] - csum[leftx - 1][topy] -
         csum[rightx][bottomy - 1] + csum[leftx - 1][bottomy - 1];
}

int main() {
  cin >> N >> K;
  rep(i, 0, N) {
    cin >> x[i] >> y[i];
    p[i] = Pii(x[i], y[i]);
    praw[i] = Pii(x[i], y[i]);
  }

  sort(p, p + N);

  rep(i, 0, N) { p[i] = Pii(i + 1, p[i].second); }

  sort(p, p + N, [](Pii &a, Pii &b) { return a.second < b.second; });

  rep(i, 0, N) { p[i] = Pii(p[i].first, i + 1); }

  sort(p, p + N);

  sort(praw, praw + N);

  repe(i, 1, N) {
    repe(j, 1, N) {
      int add = 0;
      if (p[i - 1].second == j) {
        add = 1;
      }
      csum[i][j] = csum[i - 1][j] + csum[i][j - 1] - csum[i - 1][j - 1] + add;
    }
  }

  ll ans = numeric_limits<ll>::max();
  rep(i, 0, N) {
    rep(j, 0, N) {
      rep(k, 0, N) {
        rep(l, k + 1, N) {
          ll top = praw[i].second;
          ll bottom = praw[j].second;
          if (bottom > top) continue;

          ll left = praw[k].first;
          ll right = praw[l].first;
          if (right < left) continue;

          if (cntincluded(i, j, l, k) >= K) {
            chmin(ans, (top - bottom) * (right - left));
          }
        }
      }
    }
  }

  cout << ans << endl;
}
