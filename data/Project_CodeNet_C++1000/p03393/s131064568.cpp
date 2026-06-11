#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  if (S == "zyxwvutsrqponmlkjihgfedcba")
  {
    cout << -1 << endl;
    return 0;
  }
  vector<bool> A(26, false);
  int N = S.size();
  for (int i = 0; i < N; i++)
  {
    int a = S.at(i) - 'a';
    A.at(a) = true;
  }
  if (N < 26)
  {
    cout << S;
    for (int i = 0; i < 26; i++)
    {
      if (!A.at(i))
      {
        cout << (char)('a' + i) << endl;
        break;
      }
    }
  }
  else
  {
    priority_queue<int> pq;
    for (int i = N - 1; i >= 0; i--)
    {
      int d = S.at(i) - 'a';
      pq.push(d);
      if ((int)(S.at(i) - 'a') >= pq.top())
      {
        continue;
      }
      for (int j = 0; j < i; j++)
      {
        cout << S.at(j);
      }
      char c;
      while ((int)(S.at(i) - 'a') < pq.top())
      {
        c = (char)('a' + pq.top());
        pq.pop();
      }
      cout << c << endl;
      break;
    }
  }
}