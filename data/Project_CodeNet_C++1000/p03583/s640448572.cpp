#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
typedef complex<double> cd;
static const double pi = 3.141592653589793;
// if(nextH >= 0 && nextH < H && nextW >= 0 && nextW < W)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;

  rep1(i, 3500) {
    rep1(j, 3500) {
      double tmp = 4.0/n - 1.0/i - 1.0/j;
      if(tmp <= 0) continue;
      if((abs((1.0/tmp) - (int)(1.0/tmp)) < 0.00000001)) {
        int k = 1.0/tmp;
        cout << i << " " << j << " " << k << endl;
        return 0;
      }
    }
  }
}
