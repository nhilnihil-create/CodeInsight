#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, cnt = 0, xa = 0, bx = 0, bxa = 0;
  string s;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> s;
    if (s.at(0) == 'B' && s.at(s.size() - 1) == 'A')
      bxa++;
    else if (s.at(0) == 'B')
      bx++;
    else if (s.at(s.size() - 1) == 'A')
      xa++;

    for (int j = 0; j < s.size() - 1; j++)
    {
      if (s.at(j) == 'A' && s.at(j + 1) == 'B')
      {
        cnt++;
      }
    }
  }
  cnt += min(bx, xa);
  if (bx > 0 || xa > 0)
  {
    cnt += bxa;
  }
  else if (bxa > 1)
  {
    cnt += bxa - 1;
  }
  cout << cnt << endl;
}
