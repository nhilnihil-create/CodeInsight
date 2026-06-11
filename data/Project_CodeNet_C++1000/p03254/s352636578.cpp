#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, X;
  cin >> N >> X;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < N; i++)
  {
    if (A.at(i) > X)
    {
      cout << i << endl;
      return 0;
    }
    X -= A.at(i);
  }
  cout << (X == 0 ? N : N - 1) << endl;
}
