#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int INF = 100000000;

int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  if (A + B < C * 2) {
    cout << A * X + B * Y << endl;
    return 0;
  }
  else {
    int ans = 0;
    ans += C * 2 * min(X, Y);
    if (X >= Y) {
      if (A < C * 2) {
        ans += A * (X - Y);
      }
      else {
        ans += C * 2 * (X - Y);
      }
    }
    else {
      if (B < C * 2) {
        ans += B * (Y - X);
      }
      else {
        ans += C * 2 * (Y - X);
      }
    }
    cout << ans << endl;
    return 0;
  }
}