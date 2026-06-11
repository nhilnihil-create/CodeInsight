#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int max = a[n - 1];
  int ind = lower_bound(a.begin(), a.end(), (max + 1) >> 1) - a.begin();
  int mid = a[ind];
  if (mid > max - a[ind - 1]) mid = a[ind - 1];
  if (max == mid) mid = a[ind - 2];
  cout << max << ' ' << mid << '\n';
  return 0;
}