#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Command {
  char c;
  char dir;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<Command> commands(q);
  for (int i = 0; i < q; i++) {
    char c;
    char dir;
    cin >> c >> dir;
    commands.push_back(Command({c, dir}));
  }
  
  auto find_final_position = [&](int i) -> int {
    int cur = i;
    for (const auto& command : commands) {
      if (s[cur] == command.c) {
        if (command.dir == 'R') {
          cur++;
        } else if (command.dir == 'L') {
          cur--;
        }
      }
      if (cur == n) return n;
      if (cur == -1) return -1;
    }
    return cur;
  };

  auto find_r_limit = [&]() -> int {
    if (find_final_position(n - 1) != n) return n;
    int r = n - 1;
    if (find_final_position(0) == n) return 0;
    int l = 0;
    while (r - l >= 2) {
      int m = (l + r) / 2;
      if (find_final_position(m) == n) {
        r = m;
      } else {
        l = m;
      }
    }
    return r;
  };
  int r_limit = find_r_limit();
  int r_count = n - r_limit;

  auto find_l_limit = [&]() -> int {
    if (find_final_position(0) != -1) return -1;
    int l = 0;
    if (find_final_position(n - 1) == -1) return n - 1;
    int r = n - 1;
    while (r - l >= 2) {
      int m = (l + r) / 2;
      if (find_final_position(m) == -1) {
        l = m;
      } else {
        r = m;
      }
    }
    return l;
  };
  int l_limit = find_l_limit();
  int l_count = l_limit + 1;
  // cout << "l_limit: " << l_limit << " r_limit: " << r_limit << endl;
  cout << n - (l_count + r_count) << endl;
}
