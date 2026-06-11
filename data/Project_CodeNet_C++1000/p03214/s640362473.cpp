#include <bits/stdc++.h>
using namespace std;

int main()
{
  double N, s = 0;
  cin >> N;
  vector<double> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    s += A[i];
  }
  double ave = s / N;
  double m = 100, mi;
  for (int i = 0; i < N; i++)
  {
    double d = abs(ave - A[i]);
    if (d < m)
    {
      m = d;
      mi = i;
    }
  }
  cout << mi << endl;
}