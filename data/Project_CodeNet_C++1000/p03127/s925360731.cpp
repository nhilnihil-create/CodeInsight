#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, N)
  {
    cin >> A[i];
  }

  std::sort(A.begin(), A.end());

  for (int i = 1; i < N; i++)
  {
    A[i] %= A[0];
  }

  bool changed = true;
  while (changed)
  {
    std::sort(A.begin(), A.end());

    changed = false;
    int mn = 0;
    for (int i = 0; i < N; i++)
    {
      if (A[i] == 0)
        continue;

      if (mn == 0)
      {
        mn = A[i];
        continue;
      }

      int tmp = A[i];
      A[i] %= mn;
      if (tmp != A[i])
        changed = true;
    }
  }

  rep(i, N)
  {
    if (A[i] != 0)
    {
      cout << A[i] << endl;
      return 0;
    }
  }

  return 0;
}
