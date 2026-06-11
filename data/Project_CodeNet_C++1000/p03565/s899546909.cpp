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
  string S, T;
  cin >> S >> T;
  int S_size = S.size();
  int T_size = T.size();
  debug(S, T);
  if (T_size > S_size) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  int cnt = 0;
  debug(S_size - T_size);
  for (int i = S_size - T_size; i >= 0; i--) {
    bool break_flag = 0;
    for (int j = 0; j < T_size; j++) {
      if (S[i + j] != T[j] && S[i + j] != '?') {
        break_flag = 1;
        break;
      }
    }
    if (!break_flag) {
      for (int j = 0; j < T_size; j++) {
        S[i + j] = T[j];
      }
      for (int j = 0; j < S_size; j++) {
        if (S[j] == '?') S[j] = 'a';
      }
      debug(S);
      cout << S << endl;
      return 0;
    } else {
      // if (S[i] == '?') S[i] = 'a';
      cnt++;
    }
    debug(S);
  }
  for (int i = 0; i < S_size; i++) {
    if (S[i] == '?') S[i] = 'a';
  }
  if (cnt == S_size - T_size + 1)
    cout << "UNRESTORABLE" << endl;
  else
    cout << S << endl;
  return 0;
}