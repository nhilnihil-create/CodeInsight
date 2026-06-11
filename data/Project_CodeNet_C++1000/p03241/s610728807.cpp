#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  int M;
  scanf("%d", &M);
  int ans = 1;
  for (int i = N; i <= M; ++i)
  {
    if (M % i == 0)
    {
      ans = M / i;
      break;
    }
  }
  printf("%d\n", ans);

  return 0;
}
