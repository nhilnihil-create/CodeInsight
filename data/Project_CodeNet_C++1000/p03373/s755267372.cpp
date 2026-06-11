#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
typedef long long ll;

int main() {
  int A, B, C, X, Y, yen = 0;
  cin >> A >> B >> C >> X >> Y;
  if(A >= 2 * C) {
    yen += X * 2 * C;
    Y = max(Y - X, 0);
    X = 0;
  }
  if(B >= 2 * C) {
    yen += Y * 2 * C;
    X = max(X - Y, 0);
    Y = 0;
  }
  if(A + B >= 2 * C) {
    int num = min(X, Y);
    yen += num * 2 * C;
    X -= num;
    Y -= num;
  }
  if(X > 0)
    yen += X * A;
  if(Y > 0)
    yen += Y * B;
  cout << yen << endl;
}