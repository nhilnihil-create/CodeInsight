#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, ans = 0;
  cin >> n;
  char s[100];
  scanf("%s", &s);

  for (int i = 1; i < n; i++)
  {
    map<char, int> l;
    map<char, int> r;
    int cnt = 0;
    for (int j = 0; j < i; j++)
    {
      l[s[j]]++;
    }
    for (int j = i; j < n; j++)
    {
      r[s[j]]++;
    }
    for (auto itrL = l.begin(); itrL != l.end(); itrL++)
    {
      for (auto itrR = r.begin(); itrR != r.end(); itrR++)
      {
        if (itrL->first == itrR->first)
        {
          cnt++;
          break;
        }
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
