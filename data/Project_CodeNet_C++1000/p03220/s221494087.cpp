#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, T, A, H, m(1e9), t, i{}, j; cin >> N >> T >> A;
  while (++i, cin >> H) if ((t = abs(1000 * (T - A) - 6 * H)) < m) m = t, j = i;
  cout << j;}