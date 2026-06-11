
/*
 * Welcome to my code!
 * -------------------------------------------- *
 * author : lynmisakura(twitter : @andoreiji11)
 */

#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

//Simple Array Input
#define SAI int n;cin >> n;vi a(n);ain(a)
//Simple Graph Input
#define SGI(m) for(int i=0;i<m;i++){int a,b;cin >> a >> b;g[--a].pb(--b);g[b].pb(a);}
//Simple Tree Input
#define STI SGI(n-1)

typedef long long ll;
typedef long long integer;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){
    for(int i=0;i<a.size();i++)cout << a[i] << (i < a.size()-1 ? ' ' : '\n');
}
long long gcd(long long a, long long b) {
  return b != 0 ? gcd(b, a % b) : a;
}
long long lcm(long long a, long long b) {
  return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
  long long g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}

bool func(ll n,ll a,ll b){
  
  ll g1 = gcd(a , b);
  
  ll p = a * b / g1;
  ll q = (a + b) / g1;

  ll g2 = gcd(n , p);
  
  if(4LL * p - n * q == g2){
    cout << a << ' ' << b << ' ' << n * p / g2 << '\n';
    return true;
  }else return false;

}


int main(int argc, char const *argv[])
{
  long long n;cin >> n;
  for(ll a = 1;a <= 3500;a++){
    for(ll b = 1;b <= 3500;b++){
      if(func(n,a,b))return 0; 
    }
  }
  return 0;
}
