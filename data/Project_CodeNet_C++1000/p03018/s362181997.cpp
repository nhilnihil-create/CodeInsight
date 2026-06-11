#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t ans = 0, as = 0;
  string S;
  cin >> S;
  if (S.size() >= 3)
  {
    for (int i = 0; i < S.size() - 2; i++)
    {
      if (S[i] == 'A')
        as++;
      else
        as = 0;
      if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C')
      {
        ans += as;
        string str1 = "BC", str2 = string(as, 'A');
        str1.append(str2);
        S.replace(i - as + 1, str1.size(), str1);
        as--;
        i++;
      }
    }
  }
  cout << ans << endl;
}
