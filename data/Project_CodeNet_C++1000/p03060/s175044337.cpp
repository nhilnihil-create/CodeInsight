#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> x(N), y(N);
  for (int i = 0; i < N; ++i) cin >> x[i];
  for (int i = 0; i < N; ++i) cin >> y[i];
  long long res = 0;
  for (int i = 0; i < N; ++i) {
    if (x[i] >= y[i]) res += x[i] - y[i];
  }
  cout << res << endl;
}