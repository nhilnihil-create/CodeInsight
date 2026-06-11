#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N, M;
std::string S, T;

ll gcd( ll a, ll b )
{ return b ? gcd(b,a%b) : a; }

ll lcm( ll a, ll b )
{ return a/gcd(a,b)*b; }

std::vector<char> vs;

int main()
{
  std::cin >> N >> M >> S >> T;

  ll L = lcm(N,M);

  rep( i, M ) if( N*i % M == 0 && T[i] != S[N*i/M] )
  {
    puts("-1");

    return 0;
  }

  printf( "%lld\n", L );

  return 0;
}