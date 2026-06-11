#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define rep(i,a) for(int i=0;i<(a);++i)

using ll = long long;

int N, A, B;
std::vector<int> vs;

void show( const std::vector<int> &v )
{
  rep( i, v.size() )
    printf( "%d%c", v[i], i==v.size()-1?'\n':' ' );

  return;
}

int main()
{
  scanf( "%d%d%d", &N, &A, &B );

  if( N < A+B-1 || (ll)N > (ll)A*B )
  { puts("-1"); return 0; }

  //show(vs);

  rep( i, A )
    printf( "%d ", N-(A-1-i) );

  --B;
  int p = N-A;
  while( p )
  {
    if( p == B ) while( p >= 1 )
      printf( "%d ", p ), --p;
    else
    {
      int tmp = 0; B--;
      for( ; p >= 1 && tmp < A; --p, ++tmp ) if( p == B )
        break;
      for( int j = 1; j <= tmp; ++j )
        printf( "%d ", p+j );
    }
  }

  puts("");

  return 0;
}