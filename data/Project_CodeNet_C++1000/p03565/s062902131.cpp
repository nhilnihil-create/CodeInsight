/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

void Fill(const char *const t, const int64_t t_size, char *const dest) {
  strncpy(dest, t, t_size);
}

bool Match(const string &S, const int64_t start, const string &T) {
  const int64_t s_len = static_cast<int64_t>(S.length());
  const int64_t t_len = static_cast<int64_t>(T.length());
  if (start + t_len > s_len) {
    return false;
  }
  for (int64_t i = 0; i < t_len; ++i) {
    if (S.c_str()[start + i] != T.c_str()[i] && S.c_str()[start + i] != '?') {
      return false;
    }
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S, T;
  cin >> S >> T;
  char modified[51];
  for (char &ch : modified) {
    ch = '\0';
  }
  const char *t = T.c_str();
  int64_t s_size = static_cast<int64_t>(S.length());
  int64_t t_size = static_cast<int64_t>(T.length());
  if (s_size < t_size) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  strncpy(modified, S.c_str(), s_size);
  int64_t count = 0;
  bool is_okay = false;
  for (int64_t start = s_size - 1; start >= 0; --start) {
    if (Match(S, start, T)) {
      Fill(t, t_size, &modified[start]);
      is_okay = true;
      break;
    }
  }
  if (is_okay) {
    for (int64_t i = 0; i < s_size; ++i) {
      if (modified[i] == '?') {
        modified[i] = 'a';
      }
    }
    cout << string(modified) << endl;
  } else {
    cout << "UNRESTORABLE" << endl;
  }
  return 0;
}
