#include <bits/stdc++.h>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{
  string S, T;
  int first;
  bool judge = false;
  bool a = true;
  cin >> S >> T;

  for (int i = 0; i <= (int)S.size() - (int)T.size(); i++)
  {
    if (S[i] == T[0] || S[i] == '?')
    {

      for (int j = 0; j < (int)T.size(); j++)
      {
        if (S[i + j] != T[j] && S[i + j] != '?')
          break;

        if (S[i + j] == '?')
          a = false;

        if (j == (int)T.size() - 1)
        {
          first = i;
          judge = true;
        }
      }
    }

    if (judge && a)
      break;
  }

  if (judge)
  {
    for (int j = 0; j < (int)T.size(); j++)
      S[first + j] = T[j];

    for (int i = 0; i < (int)S.size(); i++)
    {
      if (S[i] == '?')
        S[i] = 'a';
    }
    cout << S << endl;
  }
  else
    cout << "UNRESTORABLE" << endl;
}
