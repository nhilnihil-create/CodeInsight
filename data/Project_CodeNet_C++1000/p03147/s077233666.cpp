#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  int p = 0, ans = 0;
  while (N--)
    {int h; cin >> h;
    if (p < h) ans += h - p;
    p = h;}
  cout << ans << endl;}