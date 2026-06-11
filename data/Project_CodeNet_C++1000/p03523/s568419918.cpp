#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string a = "AKIHABARA";
  int p[] = {0, 4, 6, 8};

  for (int i = 0; i < (1 << 4); ++i) {
    string t = a;
    for (int j = 3; j >= 0; --j) {
      if (i & (1 << j))
        t.erase(p[j], 1);
    }
    if (s == t) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}