#include <bits/stdc++.h>
using namespace std;
int main()
  {int M, X, A, c{}; cin >> M >> M >> X;
  while (cin >> A) c += A < X;
  cout << min(c, M - c);}