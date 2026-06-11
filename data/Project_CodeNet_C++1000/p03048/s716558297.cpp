#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  ll ans = 0;
  for (int i = 0; i * R <= N; i++) {
    for (int j = 0; i * R + j * G <= N; j++) {
      int k = N - i * R - j * G;
      if (k % B == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}