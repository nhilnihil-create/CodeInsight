#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<bool> A(26, false);
  string S;
  cin >> S;
  if (S.size() < 26)
  {
    for (int i = 0; i < S.size(); i++)
    {
      int int_c = S.at(i) - 97;
      A.at(int_c) = true;
    }
    for (int i = 0; i < 26; i++)
    {
      if (!A.at(i))
      {
        char char_i = i + 97;
        cout << S << char_i << endl;
        return 0;
      }
    }
  }
  else
  {
    int int_c = S.at(25) - 97;
    A.at(int_c) = true;
    for (int i = 24; i >= 0; i--)
    {
      int_c = S.at(i) - 97;
      for (int j = int_c + 1; j < 26; j++)
      {
        if (A.at(j))
        {
          char char_i = j + 97;
          cout << S.substr(0, i) << char_i << endl;
          return 0;
        }
      }
      A.at(int_c) = true;
    }
  }
  cout << -1 << endl;
}
