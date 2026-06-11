#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <numeric>

using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

#if __has_include("debugger.cpp")
  #include "debugger.cpp"
#else
void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) > 0) cout << " ";
  print(std::forward<Tail>(tail)...);
}
# endif

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

ll cnt(ll x) {
  ll c = 0;
  FOR(i, 1, x) {
    if (x % i == 0) c++;
  }
  return c;
}

ll fact(ll x) {
  ll ans = 1;
  FOR(i, 1, x) {
    ans *= i;
  }
  return ans;
}

ll c(ll left, ll right) {
  if (left < 1) return 0;
  return fact(left) / (fact(right) * fact(left - right));
}

int main() {
  ll input(n);

  vector<ll> primes(100, 1);
  FOR(i, 2, n) {
    for (ll j = 2, p = i; p != 1;) {
      if (p % j == 0) {
        primes[j]++;
        p /= j;
      } else {
        j++;
      }
    }
  }

  ll cnt75 = 0;
  ll cnt25 = 0;
  ll cnt15 = 0;
  ll cnt5 = 0;
  ll cnt3 = 0;
  for(auto v: primes) {
    if (v >= 75) cnt75++;
    if (v >= 25) cnt25++;
    if (v >= 15) cnt15++;
    if (v >= 5) cnt5++;
    if (v >= 3) cnt3++;
  }
  /* print(c(cnt5, 2) * c(cnt3 - 2, 1)); */
  /* print(c(cnt15, 1) * c(cnt5 - 1, 1)); */
  /* print(c(cnt25, 1) * c(cnt3 - 1, 1)); */
  /* print(c(cnt75, 1)); */
  /*  */
  /* print(primes); */
  /* print(cnt3, cnt5, cnt25, cnt75); */


  ll ans = 0
  + (c(cnt5, 2) * c(cnt3 - 2, 1))
  + (c(cnt15, 1) * c(cnt5 - 1, 1))
  + (c(cnt25, 1) * c(cnt3 - 1, 1))
  + (c(cnt75, 1))
  ;
  print(ans);
}
