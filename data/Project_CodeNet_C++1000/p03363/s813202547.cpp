#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int64_t, int64_t> m;
  int64_t sum = 0;
  m[sum]++;

  int64_t res = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum += x;
    res += m[sum];
    m[sum]++;
  }

  cout << res << endl;
}
