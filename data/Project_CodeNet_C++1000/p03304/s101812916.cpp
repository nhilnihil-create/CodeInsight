#include <cstdio>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

using ll = long long;

ll n, m, d;

int main()
{
  scanf( "%lld%lld%lld", &n, &m, &d );

  printf( "%.10f\n", (m-1)*(d ? 2.0*(n-d)/n/n : 1.0/n) );

  return 0;
}