#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int r, d, x;
  cin >> r >> d >> x;
  int buf;
  for (int i = 0; i < 10; i++)
  {
    if (i == 0)
    {
      buf = r * x - d;
    }
    else
    {
      buf = r * buf - d;
    }

    cout << buf << endl;
  }
}
