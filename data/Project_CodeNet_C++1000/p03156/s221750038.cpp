#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, A, B, q;
  cin >> N >> A >> B;
  int64_t C[3] = {0, 0, 0};
  for (int i = 0; i < N; i++)
  {
    cin >> q;
    if (q <= A)
      C[0]++;
    else if (q >= B + 1)
      C[2]++;
    else
      C[1]++;
  }
  cout << min(C[0], min(C[1], C[2])) << endl;
}