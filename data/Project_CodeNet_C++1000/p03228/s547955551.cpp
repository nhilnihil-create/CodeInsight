#include <cstdio>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

int A, B, K;

int main()
{
  scanf( "%d%d%d", &A, &B, &K );

  rep( i, K )
  {
    if( i&1 )
    {
      if( B&1 )
        --B;

      A += B/2;
      B -= B/2;
    }
    else
    {
      if( A&1 )
        --A;

      B += A/2;
      A -= A/2;
    }
  }

  printf( "%d %d\n", A, B );

  return 0;
}