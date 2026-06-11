#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<long long> num(k, 0);
  for (int i = 1; i <= n; i++) {
    num[i % k]++;
  }

  long long ans = 0;
  for (int a = 0; a < k; a++) {
    int b = (k - a) % k;
    int c = (k - a) % k;
    if ((b + c) % k != 0) {
      continue;
    }
    ans += (num[a] * num[b] * num[c]);
  }
  cout << ans << endl;
  return 0;
}