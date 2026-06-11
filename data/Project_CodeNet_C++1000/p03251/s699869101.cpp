#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, M, X, Y, x, y; cin >> N >> M >> X >> Y;
  while (N--) cin >> x, X = max(X, x); while (cin >> y) Y = min(Y, y);
  puts(X < Y ? "No War" : "War");}