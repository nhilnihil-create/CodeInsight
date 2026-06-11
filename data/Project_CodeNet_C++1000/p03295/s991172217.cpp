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

int main() {
  ll input(n, m);
  vector<pair<ll, ll>> ab(m);
  REP(i, m) {
    ll input(a, b);
    ab[i] = {a, b};
  }
  sort(ab.begin(), ab.end(), [](auto &v1, auto &v2){
      return v1.first < v2.first;
      });
  ll right = -1;
  ll cnt = 0;
  REP(i, m) {
    if (ab[i].first < right) {
      right = min(ab[i].second, right);
    } else {
      right = ab[i].second;
      cnt++;
    }
  }
  print(cnt);
}
