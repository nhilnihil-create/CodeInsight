#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define debug2(x, y)                       \
  cerr << "(" << #x << "," << #y << ") = " \
       << "(" << x << "," << y << ")\n"
#define all(x) x.begin(), x.end()
#define each(a, x) for (auto& a : (x))
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define int long long
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
const int MX = 1e5 + 5, INF = 5LL << 57, MOD = 1e9 + 7;

int N, M;
string S;
vi va, vb;

void input() {
  ;
  cin >> N;
  ;
}
void solve() {
  // if (N % 4 == 0) {
  //   int k = N / 4 * 3;
  //   cout << k << " " << k << " " << k << endl;
  //   return;
  // };
  // if (N % 3 == 0) {
  //   int h = N;
  //   // 3/N = 1/n + 1/w;
  //   // 1/N = 1/3n + 1/3w
  //   // 3 = N/n + N/w;

  //   // n = N/3 * 2,w = N/3*1
  //   int n = N / 3 * 2;
  //   int w = n;
  //   cout << h << " " << n << " " << w << endl;
  //   return;

  //   // 3nw =N(n+w)
  //   // m=N/3
  //   // nw = m(n+w)
  // }
  // if (N % 2 == 0) {
  //   int h = N;
  //   int n = N;
  //   // 2/N = 1/h
  //   int w = N / 2;
  //   cout << h << " " << n << " " << w << endl;
  // }
  rep(w, 1, 3500) {
    rep(n, 1, 3500) {
      if (4 * w * n - N * n - N * w != 0) {
        if ((N * w * n) % (4 * w * n - N * n - N * w) == 0) {
          int h = (N * w * n) / (4 * w * n - N * n - N * w);
          if (h > 0) {
            cout << w << " " << n << " " << h << endl;
            return;
          }
        }
      }
    }
  }

  // // 4 = N/h + N/n + N/w
  // rep(i, 1, 3500) {
  //   rep(j, 1, 3500) {
  //     if ((N % i == 0) && (N % j == 0)) {  // N/w = 4-N/i-N/j;

  //       int w = (4 - N / i - N / j);
  //       if (w <= 0) {
  //         continue;
  //       }
  //       if (N % w != 0) continue;
  //       w = N / w;
  //       if (w > 0) {
  //         cout << i << " " << j << " " << w << endl;
  //         return;
  //       }
  //     }
  //   }
  // }
  // if (N % 4 == 0) {
  //   int k = N / 4 * 3;
  //   cout << k << " " << k << " " << k << endl;
  // };
  // ;
}
signed main() {
  input();
  solve();
  return 0;
}