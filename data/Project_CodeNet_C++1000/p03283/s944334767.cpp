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

ll N, M, Q;
ll fld[510][510];
ll S[510][510];

int main()
{
  std::cin >> N >> M >> Q;

  rep( i, M )
  {
    ll L, R;
    std::cin >> L >> R;

    --L; --R;
    L = -L;

    ++fld[L+N-1][R];
  }

  rep( i, N ) rep( j, N )
    S[i+1][j+1] = S[i+1][j]+S[i][j+1]-S[i][j]+fld[i][j];

  rep( i, Q )
  {
    ll p, q;
    std::cin >> p >> q;
    --p; --q;
    p = -p;

    std::cout << S[p+N-1+1][q+1] << std::endl;
  }

  return 0;
}