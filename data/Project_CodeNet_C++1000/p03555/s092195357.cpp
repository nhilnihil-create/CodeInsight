#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<string> C(2);
  cin >> C.at(0) >> C.at(1);

  for (int i = 0; i < 3; i++)
  {
    if (C.at(0).at(i) != C.at(1).at(2 - i))
    {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}
