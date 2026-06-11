#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using vi = vector<int>;
using vll = vector<ll>;

using pi = pair<int, int>;
using pll = pair<ll, ll>;

constexpr auto MOD = 1e9 + 7;
constexpr auto INF = 0x3f3f3f3f;

#define rep(i, a, b) for (auto i = a; i < b; ++i)

template <class T> inline T square(T x) { return x * x; };

template <class T> void print(const T &val) { cout << val << '\n'; }

template <class Iterator> void print(Iterator begin, Iterator end) {
  for (auto it = begin; it != end; ++it) {
    cout << *it << ' ';
  }

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  char x;
  cin >> x;

  if (x == 'A') {
    print('T');
  }
  if (x == 'T') {
    print('A');
  }
  if (x == 'C') {
    print('G');
  }
  if (x == 'G') {
    print('C');
  }
}
