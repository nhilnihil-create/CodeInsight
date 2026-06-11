#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int NIL = -1;
const long long INF = 1LL << 60;
const long long MOD = 1e9+7;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int N, K;
  cin >> N >> K;
  double ans = 0;
  for (int i = 1; i <= N; ++i) {
    int now = i;
    double tmp = 1.0 / N;
    while (now < K) {
      now *= 2;
      tmp /= 2;
    }
    ans += tmp;
  }
  cout << fixed << setprecision(10) << ans << endl;
}
