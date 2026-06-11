#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
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
  vector<tuple<int64, int64, int64, string>> P(M);
  int64 p, w;
  for (int i = 0; i < M; i++) {
    cin >> p >> w;
    get<0>(P[i]) = p;
    get<1>(P[i]) = w;
    get<2>(P[i]) = i;
  }
  sort(P.begin(), P.end(), [](const auto& x, const auto& y) {
    if (get<0>(x) == get<0>(y))
      return get<1>(x) < get<1>(y);
    else
      return get<0>(x) < get<0>(y);
  });

  int64 prev_p = 0;
  int64 rank = 1;
  for (int i = 0; i < M; i++) {
    ostringstream ss;
    if (get<0>(P[i]) != prev_p) {
      rank = 1;
      prev_p = get<0>(P[i]);
    }
    ss << setw(6) << setfill('0') << get<0>(P[i]) << setw(6) << setfill('0')
       << rank;
    string s(ss.str());
    get<3>(P[i]) = s;
    rank++;
  }

  sort(P.begin(), P.end(),
       [](const auto& x, const auto& y) { return get<2>(x) < get<2>(y); });

  for (int i = 0; i < M; i++) {
    cout << get<3>(P[i]) << endl;
  }

  return 0;
}