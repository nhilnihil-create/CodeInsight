#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int klen = 7;

  // 先頭から削り
  for (int i = 0; i < s.size(); i++) {
    string ss(s.begin() + i, s.end());
    if (ss == "keyence") {
      puts("YES");
      return 0;
    }
  }

  // 後方から削り
  for (int i = 0; i < s.size(); i++) {
    string ss(s.begin() + s.size() - 1 - i, s.end());
    if (ss == "keyence") {
      puts("YES");
      return 0;
    }
  }

  // 左右分割
  for (int i = 1; i < s.size() - 1; i++) {
    string l = s.substr(0, i);
    for (int j = 0; j < s.size() - i; j++) {
      string r(s.begin() + i + j, s.end());
      if (l + r == "keyence") {
        puts("YES");
        return 0;
      }
    }
  }

  puts("NO");
  return 0;
}