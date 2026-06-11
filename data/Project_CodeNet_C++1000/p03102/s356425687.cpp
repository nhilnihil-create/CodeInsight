#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, M, C, c{}; cin >> N >> M >> C;
  int B[M]; for (int &b: B) cin >> b;
  while (N--)
    {int s{C}; for (int i{}, a; i < M; ++i) cin >> a, s += a * B[i];
    c += s > 0;}
  cout << c;}