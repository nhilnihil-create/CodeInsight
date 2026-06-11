#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, X, min = 1000000, sum = 0;
  int types[101];
  cin >> N >> X;
  for (int i = 0; i < N; i++)
  {
    cin >> types[i];
    sum += types[i];
    if (types[i] < min)
      min = types[i];
  }
  X -= sum;
  int R = N;
  R += X / min;
  cout << R << endl;
  return 0;
}
