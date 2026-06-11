#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  int sum[n + 1];  // 0+i文字目までのAC数
  sum[0] = sum[1] = 0;
  for (int i = 1; i < (int)s.size(); i++) {
    sum[i + 1] = sum[i];
    if (s[i - 1] == 'A' && s[i] == 'C') sum[i + 1]++;
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l] << '\n';
  }

  return 0;
}