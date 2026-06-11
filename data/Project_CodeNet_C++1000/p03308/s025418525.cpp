#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, m{}; cin >> N;
  int A[N]; for (int &a: A) cin >> a;
  for (int i{}; i < N; ++i) for (int j{i + 1}; j < N; ++j) m = max(m, abs(A[i] - A[j]));
  cout << m;}