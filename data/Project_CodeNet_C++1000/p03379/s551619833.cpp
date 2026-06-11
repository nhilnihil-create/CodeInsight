#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  int N;
  cin >> N;

  vector<int> X(N, 0);
  vector<int> Y(N, 0);
  rep(i, N) cin >> X[i];
  Y = X;
  sort(Y.begin(), Y.end());

  int B1 = Y[N / 2 - 1];
  int B2 = Y[N / 2];

  rep(i, N) {
    if (X[i] <= B1) {
      cout << B2 << endl;
    } else {
      cout << B1 << endl;
    }
  }
}