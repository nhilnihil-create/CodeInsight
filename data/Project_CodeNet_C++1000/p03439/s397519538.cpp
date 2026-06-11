#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
string query (int pos) {
  cout << pos << endl;
  string get;
  cin >> get;
  if (get == "Vacant") {
    exit(0);
  }
  return get;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  int l = 0;
  int r = n - 1;
  string sl = query(l);
  string sr = query(r);
  while (true) {
    int mid = (l + r) / 2;
    string ms = query(mid);
    if (((mid - l) % 2 == 0 && sl != ms) || ((mid - l) % 2 == 1 && sl == ms)) {
      r = mid;
      sr = ms;
    }
    if (((r - mid) % 2 == 0 && ms != sr) || ((r - mid) % 2 == 1 && sr == ms)) {
      l = mid;
      sl = ms;
    }
  }
  return 0;
}