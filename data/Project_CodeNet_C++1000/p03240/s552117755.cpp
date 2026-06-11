#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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
  vector<ll> x(n), y(n), h(n);
  ll base = 0;
  REP(i, n) {
    cin >> x[i] >> y[i] >> h[i];
    if (h[i] != 0) {
      base = i;
    }
  }

  auto calcH = [&](ll i, ll cx, ll cy){
    return -abs(x[i] - cx) - abs(y[i] - cy);
  };

  auto check = [&](ll cx, ll cy, ll H) {
    REP(i, n) {
      if (max(H + calcH(i, cx, cy), 0ll) != h[i]) return false;
    }
    return true;
  };

	REP(cy, 100 + 1) REP(cx, 100 + 1) {
    ll H = h[base] - calcH(base, cx, cy);
    if (check(cx, cy, H)) {
      print(cx, cy, H);
      break;
    }
	}
}
