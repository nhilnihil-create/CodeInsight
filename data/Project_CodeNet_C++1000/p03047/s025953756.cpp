#include <cstdio>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

int N, K;

int main()
{
  scanf( "%d%d", &N, &K );

  printf( "%d\n", N-K+1 );

  return 0;
}