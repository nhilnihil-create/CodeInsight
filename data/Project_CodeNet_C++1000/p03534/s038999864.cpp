#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  static char s[111111];
  scanf("%s", s);

  vector<int> freq(26, 0);
  int n = strlen(s);
  REP(i, n) freq[s[i] - 'a']++;

  if (*max_element(freq.begin(), freq.end()) > (n + 2) / 3) {
    puts("NO");
  } else {
    puts("YES");
  }
  return 0;
}
