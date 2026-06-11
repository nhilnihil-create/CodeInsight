/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

char buffer[51];

bool IsPalindromic(const int32_t num) {
  snprintf(buffer, sizeof(buffer), "%d", num);
  const string str = string(buffer);
  const int32_t length = static_cast<int32_t>(str.length());
  int32_t start = 0;
  int32_t end = length - 1;
  bool is_palindromic = true;
  while (start < end) {
    if (str.c_str()[start] != str.c_str()[end]) {
      is_palindromic = false;
    }
    ++start;
    --end;
  }
  return is_palindromic;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t A, B, C, K;
  cin >> A >> B >> C >> K;
  int64_t result = A - B;
  if (K % 2 == 1) {
    result = -result;
  }
  cout << result << endl;

  return 0;
}
