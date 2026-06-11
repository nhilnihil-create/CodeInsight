#include <cstdio>
#include <cstdlib>
#include <cmath>
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
#include <tuple>
#include <vector>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define endl '\n'
#define debug(x) std::cerr << #x << " = " << (x) << endl;

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

ll N;
ll x[110], y[110], h[110];

int main() {
  std::cin >> N;

  rep( i, N )
    std::cin >> x[i] >> y[i] >> h[i];

  rep( i, 101 ) rep( j, 101 ) {
    ll prv = INF;
    bool enter = false;

    rep( k, N ) {
      ll height = llabs(i-x[k])+llabs(j-y[k])+h[k];

      if( prv != INF && ((h[k] && enter && prv != height) || (!h[k] && enter && prv > height)) )
        goto end;
      
      if( !h[k] && !enter )
        chmin( prv, height );
      if( !h[k] && enter ) {
        if( prv > height )
          goto end;
      }
      if( h[k] ) {
        if( prv != INF && prv < height )
          goto end;

        prv = height;
        enter = true;
      }
    }

    std::cout << i << ' ' << j << ' ' << prv << endl;

end:;
  }

  return 0;
}