#include <bits/stdc++.h>
using namespace std;
int N;
string S;

bool f(int n)
{
  int cnt = 0;
  for (int i = n; i < N - n; i++)
  {
    if (S[i] == '1')
      cnt++;
  }
  return cnt == 0 || cnt == (N - 2 * n);
}

int main()
{
  cin >> S;
  N = S.size();
  int l = N / 2, r = N + 1;
  while (r - l > 1)
  {
    int m = (r + l) / 2;
    if (f(N - m))
      l = m;
    else
      r = m;
  }
  cout << l << endl;
}
