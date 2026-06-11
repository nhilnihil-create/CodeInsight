#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
long double ps[1000][MAX];

int main()
{
  int N, K;
  cin >> N >> K;
  double ans = 0.0;
  for (int i = 1; i <= N; i++)
  {
    double tmp = 1.0;
    int n = i;
    while (n < K)
    {
      n *= 2;
      tmp *= 0.5;
    }
    ans += tmp;
  }
  ans /= (double)(N);
  cout << fixed << setprecision(10) << ans << endl;
}