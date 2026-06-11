#include <bits/stdc++.h>
using namespace std;
string S, T;
int n, m;

void print(int idx)
{
  string s = S.replace(idx, m, T);
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '?')
      cout << 'a';
    else
      cout << s[i];
  }
  cout << endl;
}

bool solve()
{
  for (int i = n - m; i >= 0; i--)
  {
    for (int j = 0; j < m; j++)
    {
      if (S[i + j] == '?' || T[j] == S[i + j])
      {
        if (j == m - 1)
        {
          print(i);
          return true;
        }
      }
      else
      {
        break;
      }
    }
  }
  return false;
}

int main()
{

  cin >> S >> T;
  n = S.size(), m = T.size();
  if (!solve())
    cout << "UNRESTORABLE" << endl;
}