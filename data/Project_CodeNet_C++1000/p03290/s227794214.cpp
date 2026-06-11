#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

ll d, g;
vector<int> p, c;
int ans = 1e9;

int main() {  // TODO
  cin >> d >> g;
  p = vector<int>(d);
  c = vector<int>(d);
  rep(i, d) cin >> p[i] >> c[i];

  int ans = 1e9;
  rep(i, 1 << d) {
    int step = 0;
    int score = 0;
    for (int j = d - 1; j >= 0; j--) {
      if (i >> j & 1) {
        int base = (j + 1) * 100;
        rep(s, p[j]) {
          score += base;
          step++;
          if (s == p[j] - 1) {
            score += c[j];
          }
          if (score >= g) {
            ans = min(ans, step);
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}