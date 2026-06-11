#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  vector<int> hs(N); for (auto &h: hs) cin >> h;
  int ans{0};
  for (int i = 0; i < 100; ++i)
    {bool b{true};
    for (auto &h : hs)
      if (h >= 1) {--h; if (b) ++ans; b = false;}
      else b = true;}
  cout << ans << endl;}