#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
typedef pair<int, int> pii;
const int INF = ((1LL << 30) + (1LL << 29));
const int MOD = 1000000007;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int N, M, K;
vector<int> A, B;
string S;
void input() {
  int i, j, k, x, y;
  ;
  cin >> S;
}
void solve() {
  ;
  int state = 0;
  char a = 'A', k = 'K', h = 'H', b = 'B', r = 'R', i = 'I';
  for (auto x : S) {
    switch (state) {
      case 0:
        if (x == a) {
          state = 1;
          break;
        }
        if (x == k) {
          state = 2;
          break;
        }
        state = 100;
        break;
      case 1:
        if (x == k) {
          state = 2;
          break;
        }
        state = 100;
        break;
      case 2:  // AK
        if (x == i) {
          state = 3;
          break;
        }
        state = 100;
        break;
      case 3:  // AKI
        if (x == h) {
          state = 4;
          break;
        }
        state = 100;
        break;
      case 4:  // AKIH
        if (x == a) {
          state = 5;
          break;
        }
        if (x == b) {
          state = 6;
          break;
        }
        state = 100;
        break;
      case 5:  // AKIHA
        if (x == b) {
          state = 6;
          break;
        }
        state = 100;
        break;
      case 6:  // AKIHAB
        if (x == a) {
          state = 7;
          break;
        }
        if (x == r) {
          state = 8;
          break;
        }
        state = 100;
        break;
      case 7:  // AKIHABA
        if (x == r) {
          state = 8;
          break;
        }
      case 8:  // AKIHABAR
        if (x == a) {
          state = 9;
          break;
        }
        state = 100;
        break;
      case 9:
        state = 100;
        break;
      case 100:
        break;
      default:
        break;
    }
  };

  if (state == 9 || state == 8) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
}
signed main() {
  input();
  solve();
  return 0;
}