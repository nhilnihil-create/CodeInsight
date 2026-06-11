#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  int A[N]; double x{}; for (int &a: A) cin >> a, x += a; x /= N;
  pair<double, int> m{1e9, -1}; for (int i{}; i < N; ++i) m = min(m, {abs(x - A[i]), i});
  cout << m.second;}