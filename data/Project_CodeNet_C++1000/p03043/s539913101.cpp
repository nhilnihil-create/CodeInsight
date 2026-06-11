#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
static const int INFTY = (1 << 30);
int N, K;
void func()
{
 cin >> N >> K;
 double ans = 0;
 rep(i, 1, N + 1)
 {
  int j = i, count = 0;
  while (j < K)
  {
   ++count;
   j *= 2;
  }
  int tmp = pow(2, count);
  ans += (1.0 / (tmp * N));
 }
 printf("%.10lf\n", ans);
}
int main()
{
 func();
}