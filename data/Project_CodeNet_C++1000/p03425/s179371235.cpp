#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  ll cnt[5];
  for (int i = 0; i < 5; i++) {
    cnt[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    char c = s[0];
    if (c == 'M') cnt[0]++;
    if (c == 'A') cnt[1]++;
    if (c == 'R') cnt[2]++;
    if (c == 'C') cnt[3]++;
    if (c == 'H') cnt[4]++;
  }

  ll ans = 0;
  int a[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
  int b[] = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
  int c[] = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};
  for (int i = 0; i < (int)(sizeof(a) / sizeof(int)); i++) {
    ans += cnt[a[i]] * cnt[b[i]] * cnt[c[i]];
  }

  cout << ans << endl;
  return 0;
}