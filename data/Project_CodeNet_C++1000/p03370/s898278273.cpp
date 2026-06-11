#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, X;
  cin >> N >> X;
  int sum, Xmin, K;
  sum = 0;
  Xmin = 1000000;
  rep(i, N) {
    cin >> K;
    sum += K;
    Xmin = min(Xmin, K);
  }
  cout << N + (X - sum) / Xmin << endl;
}
