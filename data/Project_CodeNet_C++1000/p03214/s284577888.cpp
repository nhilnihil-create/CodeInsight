#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int64 sum = 0;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
    sum += xs[i];
  }

  int min_arg = -1;
  int64 min_value = INT64_MAX;
  for (int i = 0; i < n; i++) {
    if (abs(sum - xs[i] * n) < min_value) {
      min_arg = i;
      min_value = abs(sum - xs[i] * n);
    }
  }
  cout << min_arg << endl;
}