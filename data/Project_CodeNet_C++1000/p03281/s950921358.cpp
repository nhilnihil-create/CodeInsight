#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, C{}; cin >> N;
  for (int i{1}; i <= N; i += 2)
    {int c{}; for (int j{1}; j <= i; ++j) c += !(i % j);
    C += c == 8;}
  cout << C;}