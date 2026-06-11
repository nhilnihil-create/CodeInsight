#include <bits/stdc++.h>
using namespace std;

bool solve(int n) {
  int total = 0;
  for (int i = 0;; ++i) {
    total = 0;
    for (int j = 0; total <= n; ++j) {
      total = 4 * i + 7 * j;
      if (total == n) return true;
    }
    if (i + 4 > n) break;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  if(solve(N)==true) cout << "Yes" <<endl;
  else cout << "No" << endl;
  return 0;
}