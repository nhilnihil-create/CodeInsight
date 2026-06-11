#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int s;
  cin >> s;
  vector<int> S;
  S.push_back(s);

  int one = 0;

  while (one < 2)
  {
    if (s % 2 == 0)
    {
      s /= 2;
    }
    else
    {
      s = (3 * s) + 1;
    }
    S.push_back(s);

    if (s == 1)
    {
      one++;
    }
  }

  for (int i = 0; i < S.size() - 1; i++)
  {
    for (int j = i + 1; j < S.size(); j++)
    {
      if (S[i] == S[j])
      {
        cout << j + 1 << endl;
        return 0;
      }
    }
  }
}
