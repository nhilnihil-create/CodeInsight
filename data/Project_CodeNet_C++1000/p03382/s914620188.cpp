#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& w : a) cin >> w;
  sort(begin(a), end(a));
  int x = a[n - 1];
  int i = lower_bound(begin(a), end(a), x / 2) - a.begin();
  int y;
  if (i == 0)
    y = a[0];
  else
    y = ((x - 2 * a[i - 1]) <= (2 * a[i] - x)) ? a[i - 1] : a[i];

  cout << x << " " << y << endl;
}