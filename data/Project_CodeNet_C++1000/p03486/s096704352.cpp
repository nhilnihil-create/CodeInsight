/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;
  vector<int32_t> s_array(s.length());
  vector<int32_t> t_array(t.length());
  for (int32_t i = 0; i < static_cast<int32_t>(s.length()); ++i) {
    s_array[i] = static_cast<int32_t>(s.c_str()[i]);
  }
  for (int32_t i = 0; i < static_cast<int32_t>(t.length()); ++i) {
    t_array[i] = static_cast<int32_t>(t.c_str()[i]);
  }
  sort(s_array.begin(), s_array.end());
  sort(t_array.begin(), t_array.end());
  reverse(t_array.begin(), t_array.end());
  bool is_okay = false;
  for (int32_t i = 0; i < max(static_cast<int32_t>(s_array.size()), static_cast<int32_t>(t_array.size())); ++i) {
    if (i >= static_cast<int32_t>(s_array.size())) {
      is_okay = true;
      break;
    } else if (i >= static_cast<int32_t>(t_array.size())) {
      is_okay = false;
      break;
    } else if (s_array[i] < t_array[i]) {
      is_okay = true;
      break;
    } else if (s_array[i] == t_array[i]) {
      // DO NOTHING
    } else {
      is_okay = false;
      break;
    }
  }
  if (is_okay) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
