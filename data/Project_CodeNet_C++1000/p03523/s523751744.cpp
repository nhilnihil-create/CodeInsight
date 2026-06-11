#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string need = "AKIHABARA";
  int ptr = 0;
  for (int i = 0; i < need.length(); i++) {
    if (ptr < s.length() && need[i] == s[ptr]) {
      ptr++;
    } else {
      if (need[i] != 'A') {
        puts("NO");
        return 0;
      }
    }
  }
  if (ptr != (int) s.length()) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}