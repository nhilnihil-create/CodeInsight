#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  string a, b;
  a = s.substr(0, 2);
  b = s.substr(2, 4);
  int x, y;
  x = stoi(a);
  y = stoi(b);

  if (x > 12)
  {
    if (y > 12 || y == 0)
    {
      cout << "NA" << endl;
      return 0;
    }
    cout << "YYMM" << endl;
    return 0;
  }
  else
  {
    if (x == 0)
    {
      if (y > 12 || y == 0)
      {
        cout << "NA" << endl;
        return 0;
      }

      cout << "YYMM" << endl;
      return 0;
    }

    if (y > 12 || y == 0)
    {
      cout << "MMYY" << endl;
      return 0;
    }
    if (y <= 12 && y > 0)
    {
      cout << "AMBIGUOUS" << endl;
      return 0;
    }
  }
}
