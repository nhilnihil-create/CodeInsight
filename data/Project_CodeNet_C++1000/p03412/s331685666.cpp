#include <cstdio>
#include <algorithm>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

constexpr int MAX_N = 200000;

int N;
int a[MAX_N], b[MAX_N], c[MAX_N];

int main()
{
  scanf( "%d", &N );
  rep( i, N )
    scanf( "%d", a+i );
  rep( i, N )
    scanf( "%d", b+i );

  int ans = 0;
  rep( t, 29 )
  {
    int T = 1<<t;
    int cnt = 0;

    rep( i, N )
      c[i] = b[i]%(2*T);

    std::sort( c, c+N );

    rep( i, N )
    {
      int m = a[i]%(2*T);

      cnt += (std::lower_bound( c, c+N, 2*T-m )-std::lower_bound( c, c+N, T-m ))%2;
      cnt += (std::lower_bound( c, c+N, 4*T-m )-std::lower_bound( c, c+N, 3*T-m ))%2;
      cnt %= 2;
    }

    ans += (cnt%2)*T;
  }

  printf( "%d\n", ans );

  return 0;
}