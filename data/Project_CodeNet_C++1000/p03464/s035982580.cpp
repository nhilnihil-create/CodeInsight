#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long low = 2, high = 2;
  for (int i = n - 1; i >= 0; --i) {
    long long newLow = ((low - 1) / a[i] + 1) * a[i];
    long long newHigh = high / a[i] * a[i] + a[i] - 1;
    if (high / a[i] * a[i] < low) {
      cout << -1 << endl;
      return 0;
    }
    low = newLow;
    high = newHigh;
  }
  cout << low << ' ' << high << endl;
  return 0;
}
