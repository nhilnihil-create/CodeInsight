#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

bool inc(char& c) {
  switch (c) {
    case '3':
      c = '5';
      return false;
    case '5':
      c = '7';
      return false;
    case '7':
      c = '3';
      return true;
  }
}

void inc(string& s) {
  bool carry = inc(s[s.size() - 1]);
  for (int i = s.size() - 2; i >= 0; --i) {
    if (!carry) break;
    carry = inc(s[i]);
  }
  if (carry) s = '3' + s;
}

bool contains(const string& s, char c) { return s.find(c) != string::npos; }

int main() {
  in(int, n);
  int ans = 0;
  string s = "3";
  while (stoll(s) <= n) {
    if (contains(s, '3') && contains(s, '5') && contains(s, '7')) {
      ++ans;
    }
    inc(s);
  }
  out(ans);
}
