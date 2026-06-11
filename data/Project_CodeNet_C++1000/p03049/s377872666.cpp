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
  int N;
  cin >> N;
  vector<string> s(N);
  cin >> s;
  string tmp;
  int last_A = 0;
  int first_B = 0;
  int num_of_AB = 0;
  int B_A = 0;
  for (int i = 0; i < N; i++) {
    if (s[i][0] == 'B') first_B++;
    for (int j = 1; j < s[i].size(); j++) {
      if (s[i][j - 1] == 'A' && s[i][j] == 'B') num_of_AB++;
    }
    if (s[i][s[i].size() - 1] == 'A') last_A++;
    if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') {
      B_A++;
    }
  }
  int ans = 0;
  if (B_A > 0) {
    last_A -= B_A;
    first_B -= B_A;
    ans += B_A - 1;
    if (last_A > 0) {
      ans++;
      last_A = max(last_A - 1, 0);
    }
    if (first_B > 0) {
      ans++;
      first_B = max(first_B - 1, 0);
    }
    ans += min(last_A, first_B);
  } else {
    ans += min(last_A, first_B);
  }
  ans += num_of_AB;
  cout << ans << endl;
  return 0;
}