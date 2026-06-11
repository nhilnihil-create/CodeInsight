#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int a, b, c;
  string s = "No";
  cin >> a >> b;

  for (c = 1; c < 4; ++c)
  {
    if ((a * b * c) & 1)
    {
      s = "Yes";
      break;
    }
  }

  cout << s << "\n";

  return 0;
}