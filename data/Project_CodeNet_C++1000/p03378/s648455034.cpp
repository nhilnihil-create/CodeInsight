#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, M, X, A, i{}; cin >> N >> M >> X;
  while (++i, cin >> A) if (A > X) break;
  cout << min(i - 1, M - i + 1);}