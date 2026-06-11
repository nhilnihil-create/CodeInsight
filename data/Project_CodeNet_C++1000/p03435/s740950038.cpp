#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  vector<vector<int>> v(3, vector<int>(3));
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> v.at(i).at(j);
    }
  }
  for (int a1 = -200; a1 < 200; a1++)
  {
    for (int a2 = -200; a2 <= 200; a2++)
    {
      for (int a3 = -200; a3 <= 200; a3++)
      {
        int b1 = v.at(0).at(0) - a1;
        int b2 = v.at(0).at(1) - a1;
        int b3 = v.at(0).at(2) - a1;
        if (
            b1 + a2 == v.at(1).at(0) &&
            b1 + a3 == v.at(2).at(0) &&
            b2 + a2 == v.at(1).at(1) &&
            b2 + a3 == v.at(2).at(1) &&
            b3 + a2 == v.at(1).at(2) &&
            b3 + a3 == v.at(2).at(2))
        {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
