#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int n, y;
  cin >> n >> y;
  bool ok = false;
  ll ans;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j + i <= n; j++) {
      for (int k = 0; k + j + i <= n; k++) {
        ans = 1000 * i + 5000 * j + 10000 * k;
        if (ans == y && n == i + j + k) {
          printf("%d %d %d\n", k, j, i);
          return 0;
        }
      }
    }
  }

  printf("%d %d %d\n", -1, -1, -1);
  return 0;
}
