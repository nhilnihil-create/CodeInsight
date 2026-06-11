#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t x, y;
  cin >> x >> y;
  if (x % y == 0)
  {
    cout << -1 << endl;
  }
  else
  {
    int64_t i = 1;
    while ((x * i) % y == 0)
    {
      i++;
    }
    cout << x * i << endl;
  }
}