#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w, n;
  cin >> h >> w >> n;
  int sr, sc;
  cin >> sr >> sc;
  sr--;
  sc--;
  string s, t;
  cin >> s >> t;

  // [xl, xu) is the live x region.
  int xl = 0;
  int xu = w;
  int yl = 0;
  int yu = h;
  for (int i = n - 1; i >= 0; i--) {
    // Aoki
    if (t[i] == 'L') {
      if (xl < xu) {
        if (xu < w) xu++;
      }
    } else if (t[i] == 'R') {
      if (xl < xu) {
        if (xl > 0) xl--;
      }
    } else if (t[i] == 'U') {
      if (yl < yu) {
        if (yu < h) yu++;
      }
    } else if (t[i] == 'D') {
      if (yl < yu) {
        if (yl > 0) yl--;
      }
    }

    // Takahashi
    if (s[i] == 'L') {
      if (xl < xu) {
        if (xl < w) xl++;
      }
    } else if (s[i] == 'R') {
      if (xl < xu) {
        if (xu > 0) xu--;
      }
    } else if (s[i] == 'U') {
      if (yl < yu) {
        if (yl < h) yl++;
      }
    } else if (s[i] == 'D') {
      if (yl < yu) {
        if (yu > 0) yu--;
      }
    }
  }

  if (yl <= sr && sr < yu && xl <= sc && sc < xu) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}