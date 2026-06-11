#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

template<class T>
void print(vector<T> a) {
  cout << "[ ";
  REP(i, a.size()) cout << a[i] << " ";
  cout << "]" << endl;
}

void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...);
}

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

int main() {
  ll input(n);
  vector<ll> a(n), b(n), c(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  REP(i, n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  vector<ll> cumsum(n);
  FOR(i, 0, n - 1) {
    auto c_it_end = upper_bound(c.begin(), c.end(), b[i]);
    cumsum[i] = n - distance(c.begin(), c_it_end);
  }
  partial_sum(cumsum.rbegin(), cumsum.rend(), cumsum.rbegin());
  cumsum.push_back(0);
  
  ll ans = 0;
  FOR(i, 0, n - 1) {
    auto b_it_end = upper_bound(b.begin(), b.end(), a[i]);
    ans += cumsum[distance(b.begin(), b_it_end)];
  }
  cout << ans << endl;
}
