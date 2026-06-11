#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> cnt(n);
  for (int i = 1; i < n; i++) {
    cnt[i] = cnt[i - 1] + (s[i - 1] == 'A' && s[i] == 'C');
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << cnt[r] - cnt[l] << '\n';
  }
  return 0;
}
