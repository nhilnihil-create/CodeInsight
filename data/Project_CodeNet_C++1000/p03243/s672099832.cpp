#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, n, m; cin >> N; n = N / 100; m = 100 * n + 10 * n + n;
  cout << (m >= N ? m : 100 * (n + 1) + 10 * (n + 1) + n + 1);}