#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, a, all = 1, odds = 1;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    all *= 3;
    if (a % 2 == 0)
    {
      odds *= 2;
    }
  }
  cout << all - odds << endl;
}
