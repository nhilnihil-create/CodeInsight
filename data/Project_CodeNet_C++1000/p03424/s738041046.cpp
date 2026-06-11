#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
  int N;
  // string op;
  cin >> N;
  int p = 0, w = 0, g = 0, y = 0;

  rep(i, N)
  {
    string s;
    cin >> s;
    // cout << s << endl;
    if (s == "P")
    {

      p = 1;
    }
    else if (s == "W")
    {

      w = 1;
    }
    else if (s == "G")
    {

      g = 1;
    }
    else if (s == "Y")
    {
      y = 1;
    }
  }
  // cout << p << w << g << y << endl;

  if ((p + w + g + y) == 3)
  {
    cout << "Three" << endl;
  }
  else
  {
    cout << "Four" << endl;
  }
}