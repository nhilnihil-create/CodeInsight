#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<int64_t> X(N + 1);
  X.at(0) = 2;
  X.at(1) = 1;
  rep2(i, 2, N) {
    X.at(i) = X.at(i - 1) + X.at(i - 2);
  }
  cout << X.at(N) << endl;
}
