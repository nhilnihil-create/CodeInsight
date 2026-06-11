#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using ll = long long;
using P = std::pair<ll, ll>;

constexpr ll INF = 1ll<<60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

ll T;

ll gcd( ll a, ll b )
{ return b ? gcd(b,a%b) : a; }

int main()
{
  std::cin >> T;

  rep( t, T )
  {
    ll A, B, C, D;
    std::cin >> A >> B >> C >> D;

    if( D-B < 0 )
    {
      puts("No");

      continue;
    }

    ll G = gcd( B, D );
    ll x = A-B;

    if( x < 0 )
    {
      puts("No");

      continue;
    }
    
    ll L = C-B;

    if( L >= 0 )
    {
      puts("Yes");

      continue;
    }

    ll y = L+(x%G-L%G+G)%G;

    if( y == L )
      y += G;

    //printf( "y: %lld\n", y );

    if( std::min(x,y) >= 0 )
      puts("Yes");
    else
      puts("No");
  }

  return 0;
}