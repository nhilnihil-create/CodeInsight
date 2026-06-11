#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x, y, t;
  bool flag = false;
  cin >> n;
  t = x = y = 0;

  for (int i = 0; i < n; i++)
  {
    int t1, x1, y1, t2, x2, y2;
    cin >> t1 >> x1 >> y1;
    t2 = abs(t1 - t);
    x2 = abs(x1 - x);
    y2 = abs(y1 - y);
    if ((x1 + y1) % 2 == t1 % 2 && t2 >= x2 + y2)
    {
      flag = true;
      t = t1;
      x = x1;
      y = y1;
    }
    else
    {
      flag = false;
      break;
    }
  }
  if (flag)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
