#include <bits/stdc++.h>
using namespace std;
int INF(1e7);
int main()
  {int N, T, m{INF}, c, t; cin >> N >> T;
  while (cin >> c >> t) if (t <= T) m = min(m, c);
  if (m < INF) cout << m; else puts("TLE");}