#include <bits/stdc++.h>
using namespace std;
int main()
  {int x, s{}, m{}; while (cin >> x) s += (x + 9) / 10 * 10, m = max(m, (10 - x % 10) % 10);
  cout << s - m;}