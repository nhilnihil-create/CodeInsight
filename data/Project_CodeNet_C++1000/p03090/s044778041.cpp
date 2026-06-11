#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N; // 本数 : N - 2
  queue<pair<int, int>> Q;
  if (N % 2)
  {
    for (int n = 1; n < N; n++)
    {
      for (int i = n + 1; i < N; i++)
      {
        if (n == i || n == (N - i))
          continue;
        Q.push({n, i});
      }
    }
    for (int i = 1; i < N; i++)
    {
      Q.push({N, i});
    }
  }
  else
  {
    for (int n = 1; n <= N; n++)
    {
      for (int i = n + 1; i <= N; i++)
      {
        if (n == i || n == (N + 1 - i))
          continue;
        Q.push({n, i});
      }
    }
  }
  cout << Q.size() << endl;
  while (Q.size())
  {
    cout << Q.front().first << ' ' << Q.front().second << endl;
    Q.pop();
  }
}
