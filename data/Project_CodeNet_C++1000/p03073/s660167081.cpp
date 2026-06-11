#include <bits/stdc++.h>
using namespace std;
int main()
  {int n{}, C{};
  char c; for (; cin >> c; ++n) C += c != n % 2 + '0';  
  cout << min(C, n - C);}