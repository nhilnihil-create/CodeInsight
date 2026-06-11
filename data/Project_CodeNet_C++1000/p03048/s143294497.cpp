#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;
  for (int r = 0; r * R <= N; ++r) {
    for (int g = 0; g * G <= N; ++g) {
      int num = N - r*R - g*G;
      if (num < 0) continue;
      if (num % B == 0) {
        ans++;
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}