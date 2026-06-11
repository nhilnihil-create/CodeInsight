#include <bits/stdc++.h>
using namespace std;

int main()
{
  int r, D, x;

  cin >> r >> D >> x;

  int ans = 0;

  for (int i = 0; i < 10; i++)
  {
    cout << (r * x - D) << endl;
    x = r * x - D;
  }
}
