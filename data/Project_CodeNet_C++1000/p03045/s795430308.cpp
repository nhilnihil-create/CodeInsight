#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

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

vector<ll> cards;

ll find(ll node) {
  if (node == cards[node]) return node;
  ll root = find(cards[node]);
  cards[node] = root;
  return root;
}

void uni(ll a, ll b) {
  cards[find(b)] = find(a);
}

int main() {
  ll input(n, m);
  cards = vector<ll>(n + 1);
  REP(i, n + 1) cards[i] = i;
  REP(i, m) {
    ll input(x, y, z);
    uni(x, y);
  }

  set<ll> roots;
  for (auto v: cards) {
    roots.insert(find(v));
  }

  cout << roots.size() - 1 << endl;
}
