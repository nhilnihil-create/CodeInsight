#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005], t[200005];

int main() {
  int n;
  cin >> n;
  for (int ni = 0; ni < n; ni++) {
    cin >> a[ni];
  }
  for (int ni = 0; ni < n; ni++) {
    cin >> b[ni];
  }
  int ans = 0;
  int bitmask = 0;
  for (int i = 0; i <= 28; i++) {
    bitmask |= (1 << i);
    int ti = 0;
    for (int ni = 0; ni < n; ni++) {
      if ((a[ni] & (1 << i)) == 0) {
        t[ti++] = a[ni];
      }
    }
    for (int ni = 0; ni < n; ni++) {
      if ((a[ni] & (1 << i)) > 0) {
        t[ti++] = a[ni];
      }
    }
    memcpy(a, t, sizeof(a));
    ti = 0;
    for (int ni = 0; ni < n; ni++) {
      if ((b[ni] & (1 << i)) == 0) {
        t[ti++] = b[ni];
      }
    }
    for (int ni = 0; ni < n; ni++) {
      if ((b[ni] & (1 << i)) > 0) {
        t[ti++] = b[ni];
      }
    }
    memcpy(b, t, sizeof(b));
    int al = 0, ar = 0;
    int bit = 0;
    for (int ni = n - 1; ni >= 0; ni--) {
      while (al < n && (a[al] & bitmask) + (b[ni] & bitmask) < (1 << i)) al++;
      while (ar < n && (a[ar] & bitmask) + (b[ni] & bitmask) < (1 << (i + 1))) ar++;
      bit += (ar - al);
      bit %= 2;
    }
    al = 0, ar = 0;
    for (int ni = n - 1; ni >= 0; ni--) {
      while (al < n && (a[al] & bitmask) + (b[ni] & bitmask) < (1 << (i + 1)) + (1 << i)) al++;
      while (ar < n && (a[ar] & bitmask) + (b[ni] & bitmask) < (1 << (i + 2))) ar++;
      bit += (ar - al);
      bit %= 2;
    }
    ans |= (bit << i);
  }
  cout << ans << endl;
  return 0;
}
