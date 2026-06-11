#include <bits/stdc++.h>
using namespace std;
int main()
  {int A, B, C, K, m; cin >> A >> B >> C >> K, m = max({A, B, C});
  cout << A + B + C - m + (m << K);}