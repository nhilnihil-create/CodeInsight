#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, d, x, c = 0;
  cin >> n >> d >> x;
  for (int i = 0; i < n; i++)
  {
    int a, y = 0;
    cin >> a;
    while (1)
    {
      int tmp = (y * a) + 1;
      if (tmp > d)
      {
        break;
      }
      c++;
      y++;
    }
  }
  cout << c + x << endl;
}
