#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int a, b, c, d, e;
  int ans = 0;
  rep(i, N) {
    int I = i + 1;
    a = I % 10;
    b = (I - a) % 100 / 10;
    c = (I - a - b * 10) % 1000 / 100;
    d = (I - a - b * 10 - c * 100) % 10000 / 1000;
    e = (I - a - b * 10 - c * 100 - d * 1000) % 100000 / 10000;
    if(A <= a + b + c + d + e && a + b + c + d + e <= B) {
      ans += I;
    }
  }
  cout << ans << endl;
}