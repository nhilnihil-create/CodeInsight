#include <iostream>
#include <string>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

int N, Q;
std::string s;
std::string t[200010], d[200010];
int ans;

bool C1( int x )
{
  rep( q, Q )
  {
    if( s[x] == t[q][0] )
      x += (d[q][0]=='L'?-1:1);

    if( x < 0 )
      return false;
  }

  return true;
}

bool C2( int x )
{
  rep( q, Q )
  {
    if( s[x] == t[q][0] )
      x += (d[q][0]=='L'?-1:1);

    if( x >= N )
      return false;
  }

  return true;
}

int main()
{
  std::cin >> N >> Q >> s;

  rep( i, Q )
    std::cin >> t[i] >> d[i];

  int lb = -1, ub = N;

  while( ub-lb > 1 )
  {
    int mid = (lb+ub)/2;

    (C1(mid)?ub:lb) = mid;
  }

  ans += ub;

  lb = -1, ub = N;

  while( ub-lb > 1 )
  {
    int mid = (lb+ub)/2;

    (C2(mid)?lb:ub) = mid;
  }

  ans += N-ub;

  printf( "%d\n", N-ans );

  return 0;
}