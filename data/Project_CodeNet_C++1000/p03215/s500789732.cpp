#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, ans = 0;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  queue<int64_t> Q, S, R; // S: selected, R: removed
  for (int64_t i = 0; i < N; i++)
  {
    int64_t s = 0;
    for (int64_t j = i; j < N; j++)
    {
      s += A.at(j);
      Q.push(s);
    }
  }
  for (int64_t i = 60; i >= 0; i--)
  {
    int64_t n = Q.size();
    while (Q.size())
    {
      if (Q.front() & (1LL << i))
      {
        S.push(Q.front());
      }
      else
      {
        R.push(Q.front());
      }
      Q.pop();
    }
    if (S.size() < K)
    {
      while (R.size())
      {
        Q.push(R.front());
        R.pop();
      }
      while (S.size())
      {
        Q.push(S.front());
        S.pop();
      }
    }
    else
    {
      ans |= (1LL << i);
      while (R.size())
      {
        R.pop();
      }
      while (S.size())
      {
        Q.push(S.front());
        S.pop();
      }
    }
  }
  cout << ans << endl;
}