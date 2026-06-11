#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  const int maxp = 55555;
  int N;
  cin >> N;
  vector<vector<int>> v(5, vector<int>());
  for (int i = 2; i <= maxp; i++) {
    if (is_prime(i)) {
      v[i % 5].push_back(i);
    }
  }
  for (int i = 1; i <= 4; i++) {
    if (v[i].size() >= N) {
      for (int j = 0; j < N; j++) {
        if (j > 0) cout << " ";
        cout << v[i][j];
      }
      cout << endl;
      break;
    }
  }

  return 0;
}
/* vim:set fdm=marker: */
