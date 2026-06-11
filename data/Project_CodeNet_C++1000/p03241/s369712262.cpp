#include <bits/stdc++.h>
using namespace std;

set<int> divisor(int n) {
  int t = sqrt(n);
  set<int> ret;
  for (int i = 1; i <= t; i++) {
    if (n % i == 0) {
      ret.insert(i);
      ret.insert(n / i);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, M;
  cin >> N >> M;
  if (M % N == 0) {
    cout << M / N << endl;
    return 0;
  }
  set<int> s = divisor(M);
  int max = 0;
  for (int x : s) {
    if (x <= M / N) {
      max = x;
    }
  }
  cout << max << endl;
}
