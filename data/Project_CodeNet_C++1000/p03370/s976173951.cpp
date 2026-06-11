#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, X, m, s{}, M(1e5); cin >> N >> X; for (int i{N}; i--;) {cin >> m; M = min(M, m); s += m;}
  cout << N + (X - s) / M;}