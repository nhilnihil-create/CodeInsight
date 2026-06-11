#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, D, X, s{}, A; cin >> N >> D >> X;
  while (N--) cin >> A, s += (D - 1) / A + 1;
  cout << s + X;}