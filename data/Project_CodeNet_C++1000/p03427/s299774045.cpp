#include <bits/stdc++.h>
using namespace std;

string n;

long long solve();

int main() {
  cin >> n;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0, len = n.size(), sum = 0;
  for (int i = 0; i < len; ++i) {
    sum += n[i] - '0';
    res = max(res, sum - 1 + 9 * (len - 1 - i));
  }
  return max(res, sum);
}