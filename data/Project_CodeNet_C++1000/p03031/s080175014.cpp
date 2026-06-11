#include "bits/stdc++.h"

#pragma warning(disable : 4996)

typedef long long ll;
#define all(x) (x).begin(), (x).end()  // sortなどの引数を省略
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define max3(x, y, z) max(x, max(y, z))
#define min3(x, y, z) min(x, min(y, z))

#ifdef _MSC_FULL_VER  //デバッグ出力
#define dout cout
#define debug() if (true)
#define check(x) std::cout << "★" << #x << "の値:" << (x) << endl
#define pass(x) std::cout << "☆" << x << endl
#else
#define dout \
  if (false) cout
#define debug() if (false)
#define check(x) \
  if (false) cout << "★" << #x << "の値:" << (x) << endl
#define pass(x) \
  if (false) cout << "☆" << x << endl
#endif

using namespace std;
//#define int long long;

double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
ll idistance(ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
signed main() {
  int N, M;
  cin >> N >> M;
  int k;
  vector<vector<ll>> ks(M, vector<ll>(N, -1));
  vector<ll> ms(M);
  rep(i, M) {
    cin >> k;
    rep(j, k) {
      cin >> ks[i][j];
      ks[i][j]--;
    }
  }
  //cout << "-" << endl;
  rep(i, M) { cin >> ms[i]; }
  //cout << "F" << endl;
  int c = 0;
  for (int bit = 0; bit < (1 << N); ++bit) {
    vector<int> S(N);  //目的の集合
    for (int i = 0; i < N; ++i) {
      if (bit & (1 << i)) {
        S[i] = 1;
      }
    }
    int f = 1;
    rep(i, M) {
      int tmp = 0;
      rep(j, N) {
        if (ks[i][j] != -1) {
          if (S[ks[i][j]] == 1) {
            tmp++;
          }
        }
      }
      if (tmp % 2 != ms[i]) {
        f = 0;
      }
    }
    if (f == 1) {
      c++;
    }
  }
  cout << c;
}
