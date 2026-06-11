#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
string str;
string target = "keyence";
int main()
{
  cin >> str;
  if (str == target)
  {
    puts("YES");
    return 0;
  }
  int n = str.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      //delete [i,j]
      string S = "";
      for (int k = 0; k < n; k++)
      {
        if (i <= k && k <= j)
        {
          continue;
        }
        else
          S.push_back(str[k]);
      }
      if (S == target)
      {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}