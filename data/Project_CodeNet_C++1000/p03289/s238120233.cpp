#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  string S;
  cin >> S;
  if (S.at(0) == 'A')
  {
    int cnt = 0;
    for (int i = 1; i < S.size(); ++i)
    {
      if (isupper(S[i])) // 大文字か比較
      {
        if (i == 1 || i == S.size() - 1 || S[i] != 'C')
        {
          cout << "WA" << endl;
          return 0;
        }
        cnt++;
      }
    }
    if (cnt != 1)
    {
      cout << "WA" << endl;
      return 0;
    }
  }
  else
  {
    cout << "WA" << endl;
    return 0;
  }
  cout << "AC" << endl;
  return 0;
}