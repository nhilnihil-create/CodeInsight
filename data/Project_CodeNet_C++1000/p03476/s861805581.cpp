#include <bits/stdc++.h>
using namespace std;

bool isp(int n) {
  if (n < 2) return false;
  else if (n == 2) return true;
  else if (n % 2 == 0) return false;
  for (int i = 3; i <= (int)sqrt(n); i += 2) if (n % i == 0) return false;
  return true;
}

int main() {
  int Q;
  cin >> Q;
  int N = 1000000;
  vector<int> V(N);
  for (int i = 0; i < N; i++) {
    if (isp(i) && isp((i + 1) / 2)) V.at(i) = 1;
  }
  vector<int> R(N + 1);
  for (int i = 1; i <= N; i++) {
    R.at(i) = R.at(i - 1) + V.at(i - 1);
  }
  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    cout << R.at(r + 1) - R.at(l) << "\n";
  }
}