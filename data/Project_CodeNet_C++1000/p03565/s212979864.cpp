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

std::string S, T;
std::set<std::string> st;

bool equal( ll idx, const std::string &T ) {
  repi( i, idx, idx+T.size() ) {
    if( i >= S.size() )
      return false;

    if( S[i] != '?' && S[i] != T[i-idx] )
      return false;
  }

  return true;
}

int main()
{
  std::cin >> S >> T;

  rep( i, S.size() ) {
    if( equal( i, T ) ) {
      auto t = S.substr(0,i);
      rep( j, t.size() ) if( t[j] == '?' )
        t[j] = 'a';

      auto t2 = i+T.size() < S.size() ? S.substr( i+T.size() ) : "";
      rep( j, t2.size() ) if( t2[j] == '?' )
        t2[j] = 'a';

      st.emplace( t+T+t2 );
    }
  }

  std::cout << (st.empty() ? "UNRESTORABLE" : *st.begin()) << std::endl;

  return 0;
}