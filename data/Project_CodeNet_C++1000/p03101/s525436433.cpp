#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int hw, ww, h, w;
  cin >> hw >> ww >> h >> w;
  int ans = hw * ww - h * ww - w * hw + h * w;
  cout << ans << '\n';
}