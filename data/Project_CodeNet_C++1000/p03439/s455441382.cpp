#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) {
    if (i)
      os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
  for (auto val : array)
    std::cout << val << ", ";
  std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << std::setprecision(10);

  int n; std::cin >> n;
  vector<bool> isMale(n, false);
  std::cout << 0 << std::endl;
  string s; std::cin >> s;
  if (s == "Male")
    for (int i = 0; i < n; i+=2) isMale[i] = true;
  else if (s == "Female")
    for (int i = 1; i < n; i+=2) isMale[i] = true;
  else
    return 0;
  int l = 0, r = n;
  rep(i, 19) {
    int mid = (l + r) / 2;
    std::cout << mid << std::endl;
    std::cin >> s;
    if (s == "Male") {
      if (isMale[mid]) l = mid;
      else r = mid;
    } else if (s == "Female") {
      if (!isMale[mid]) l = mid;
      else r = mid;
    } else
      return 0;
  }
}
