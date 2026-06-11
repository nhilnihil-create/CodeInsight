#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int a, b, t, p = 0;
  cin >> a >> b >> t;

  for (int i = a; i <= t + 0.5 && a <= t + 0.5; i += a)
  {
    p += b;
  }

  cout << p << "\n";
  return 0;
}