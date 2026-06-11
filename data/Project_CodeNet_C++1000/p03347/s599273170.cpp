#include <bits/stdc++.h>
using namespace std;
const int64_t MAXN = 200010;
int64_t N;
vector<int64_t> A(MAXN);

int64_t solve()
{
  if (A[0] != 0)
  {
    return -1;
  }
  int64_t n = 0, ret = 0;
  for (int i = 0; i < N; i++)
  {
    if (A.at(i) == 0)
    {
      n = 0;
    }
    else if (A.at(i) > n + 1)
    {
      return -1;
    }
    else if (A.at(i) == n + 1)
    {
      ret++;
      n++;
    }
    else
    {
      ret += A.at(i);
      n = A.at(i);
    }
  }
  return ret;
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  cout << solve() << endl;
}