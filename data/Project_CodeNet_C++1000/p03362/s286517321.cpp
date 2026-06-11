#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  const int m = 55556;
  vector<bool> primes(m, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i * i < m; i++) {
    if (!primes[i]) continue;
    for (int j = i + i; j < m; j += i) {
      primes[j] = false;
    }
  }
  vector<int> ans;
  for (int i = 2; ans.size() < n; i++) {
    if (primes[i]) {
      if (i % 5 == 1) {
        ans.emplace_back(i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}