#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int64> A(N);
  cin >> A;
  sort(A.begin(), A.end());
  vector<pair<int64, int64>> p(M);
  for (int i = 0; i < M; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end(), [](const auto& x, const auto& y) {
    if (x.second == y.second)
      return x.first > y.first;
    else
      return x.second > y.second;
  });
  debug(p);
  int idx = 0;
  int64 ans = 0;
  for (int i = 0; i < M; i++) {
    int b = p[i].first;
    while (b != 0 && A[idx] < p[i].second && idx < N) {
      idx++;
      b--;
      ans += p[i].second;
    }
    debug(ans);
  }
  for (int i = idx; i < N; i++) {
    ans += A[i];
  }
  cout << ans << endl;
  return 0;
}