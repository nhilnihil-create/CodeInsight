#include <cstdio>
#include <cmath>
#include <algorithm>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

constexpr int MAX_N = 100000;

int n;
int a[MAX_N];
int ma;

int main()
{
  scanf( "%d", &n );
  rep( i, n )
    scanf( "%d", a+i ), ma = std::max( ma, a[i] );

  int r = 0;
  rep( i, n )
  {
    if( fabs(r-(double)ma/2.0) > fabs(a[i]-(double)ma/2.0) )
      r = a[i];
  }

  printf( "%d %d\n", ma, r );

  return 0;
}