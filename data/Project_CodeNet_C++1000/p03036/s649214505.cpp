#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int R, D, X;
  cin >> R >> D >> X;
  int sum = X;
  rep(i, 10) {
    X = sum * (R - 1) - D;
    sum += X;
    cout << sum << endl;
  }
}