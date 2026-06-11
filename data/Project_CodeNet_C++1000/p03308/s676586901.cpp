#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, m(1e9), M{}, A; cin >> N;
  while (cin >> A) m = min(m, A), M = max(M, A);
  cout << M - m;}