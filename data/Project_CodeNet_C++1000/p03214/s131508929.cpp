#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int sum = 0;
  for (int i = 0; i < n; ++i)
    sum += a[i];

  double avg = (double)sum / n;

  int ans = 0;
  double d = abs((double)a[0] - avg);
  for (int i = 1; i < n; ++i) {
    double tmp = abs((double)a[i] - avg);
    if (tmp < d) {
      d = tmp;
      ans = i;
    }
  }

  cout << ans << endl;
}