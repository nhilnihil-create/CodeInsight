#include <bits/stdc++.h>
 
using namespace std;
 
const int md = 1e9 + 7;
 
int add(int x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
  return x;
}
 
int sub(int x, int y) {
  x -= y;
  if (x < 0) {
    x += md;
  }
  return x;
}
 
int mul(int x, int y) {
  return (long long)x * y % md;
}
 
int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> inv(n + 1);
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = mul(md - md / i, inv[md % i]);
  }
  int coef = 0;
  for (int i = 1; i <= n; ++i) {
    coef = add(coef, inv[i]);
  }
  int answer = 0;
  for (int i = 0; i < n; ++i) {
    answer = add(answer, mul(coef, a[i]));
    if (i + 1 < n) {
      coef = add(coef, inv[i + 2]);
      coef = sub(coef, inv[n - i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    answer = mul(answer, i);
  }
  cout << answer << endl;
  return 0;
}
