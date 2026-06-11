#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s; cin >> s;
  int k; cin >> k;
  for (int i = 0; i < k; i++)
  {
    char c = s[i];
    if (c != '1')
    {
      cout << c << endl;
      return 0;
    }
  }
  cout << 1 << endl;
}