#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> primes, ans{2};
  primes.push_back(2);
  for (int i = 3; i <= 55555; i += 2) {
    for (auto p: primes) {
      if (i % p == 0) break;
      if (i < p * p) {
        primes.push_back(i);
        if (i % 5 == 1) ans.push_back(i);
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i];
    if (i < n - 1) cout << " ";
    else cout << endl;
  }

  return 0;
}