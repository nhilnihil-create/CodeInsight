#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, hh, ww;
  cin >> h >> w >> hh >> ww;

  int ans = h*w - hh*w - ww*(h-hh);
  cout << ans << endl;
}