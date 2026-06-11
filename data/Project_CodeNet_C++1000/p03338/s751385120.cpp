#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;

  auto get_same_num = [&](int pos) {
    string f = s.substr(0, pos);
    string l = s.substr(pos);

    int count = 0;
    char c = 'a';
    while (c <= 'z') {
      if (f.find(c) != string::npos && l.find(c) != string::npos) count++;
      c++;
    }
    return count;
  };

  int ans(0);
  for (int i = 1; i < n - 1; i++) {
    ans = max(get_same_num(i), ans);
  }

  cout << ans << endl;
}
