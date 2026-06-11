#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> a;

bool is_valid(int idx, vector<int> &cnts) {
  for (int i = 0; i < 20; ++i) {
    if (a[idx] >> i & 1 && cnts[i] > 0) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> cnts(n, 0);
  ll ans = n;
  int right = 0;
  for (int left = 0; left < n - 1; ++left) {
    while (right < n && is_valid(right, cnts)) {
      for (int j = 0; j < 20; ++j) {
	if (a[right] >> j & 1) cnts[j]++;
      }
      right++;
    }
    ans += (right - left - 1);
    if (right == left) ++right;
    for (int j = 0; j < 20; ++j) {
      if (a[left] >> j & 1) cnts[j]--;
    }
  }
  cout << ans << endl;
  return 0;
}
